import os
import logging
from dotenv import load_dotenv

load_dotenv()

from fastapi import FastAPI, Form, Response, UploadFile, File
from fastapi.staticfiles import StaticFiles
from fastapi.middleware.cors import CORSMiddleware
from twilio.twiml.messaging_response import MessagingResponse

from agent import run_farmer_agent
from audio_service import transcribe_audio_stream, generate_voice_response

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")
logger = logging.getLogger("FarmVoice")

app = FastAPI(title="FarmVoice AI Production API")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

os.makedirs("static/uploads", exist_ok=True)
os.makedirs("static/audio", exist_ok=True)
app.mount("/static", StaticFiles(directory="static"), name="static")

@app.get("/health")
def health():
    return {"status": "healthy", "service": "FarmVoice AI v1.0"}

@app.post("/api/diagnose")
async def web_diagnose(
    text: str = Form(default=""),
    file: UploadFile = File(default=None)
):
    """Direct REST endpoint for browsers, mobile apps, or manual testing."""
    image_url = None
    if file and file.filename:
        file_path = f"static/uploads/{file.filename}"
        with open(file_path, "wb") as f:
            f.write(await file.read())
        public_url = os.getenv("PUBLIC_URL", "http://localhost:8000").rstrip("/")
        image_url = f"{public_url}/{file_path}"

    text_output = run_farmer_agent(user_message=text, image_url=image_url)
    
    # Generate TTS speech audio file
    voice_path = ""
    try:
        voice_path = generate_voice_response(text_output)
        public_url = os.getenv("PUBLIC_URL", "http://localhost:8000").rstrip("/")
        voice_path = f"{public_url}{voice_path}"
    except Exception as e:
        logger.error(f"TTS generation error: {e}")

    return {
        "text_response": text_output,
        "audio_url": voice_path
    }

@app.post("/webhook/whatsapp")
async def twilio_whatsapp_webhook(
    Body: str = Form(default=""),
    NumMedia: int = Form(default=0),
    MediaUrl0: str = Form(default=None),
    MediaContentType0: str = Form(default="")
):
    """Complete WhatsApp Twilio Webhook."""
    user_query = Body.strip()
    image_url = None
    is_voice = False

    if NumMedia > 0 and MediaUrl0:
        content_type = MediaContentType0.lower()
        if content_type.startswith("audio/") or "ogg" in content_type:
            is_voice = True
            try:
                transcript = transcribe_audio_stream(MediaUrl0, content_type)
                user_query = f"{user_query} {transcript}".strip()
                logger.info(f"Transcribed Voice Input: {transcript}")
            except Exception as e:
                logger.error(f"Audio processing error: {e}")
                twiml = MessagingResponse()
                twiml.message("Could not process voice note. Please speak clearly or send text.")
                return Response(content=str(twiml), media_type="application/xml")
        elif content_type.startswith("image/"):
            image_url = MediaUrl0

    if not user_query and not image_url:
        twiml = MessagingResponse()
        twiml.message("Hello! Send a photo of your crop, a voice note, or ask for market prices.")
        return Response(content=str(twiml), media_type="application/xml")

    agent_output = run_farmer_agent(user_message=user_query, image_url=image_url)

    twiml = MessagingResponse()
    msg = twiml.message()
    msg.body(agent_output)

    # If incoming media was voice, send back a voice note attachment
    if is_voice:
        try:
            rel_audio = generate_voice_response(agent_output)
            public_url = os.getenv("PUBLIC_URL", "").rstrip("/")
            if public_url and "localhost" not in public_url:
                msg.media(f"{public_url}{rel_audio}")
        except Exception as e:
            logger.error(f"TTS response attaching failed: {e}")

    return Response(content=str(twiml), media_type="application/xml")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("main:app", host="0.0.0.0", port=int(os.getenv("PORT", 8000)), reload=True)
