import os
from pathlib import Path

FILES = {}

FILES["requirements.txt"] = """fastapi==0.111.0
uvicorn==0.30.1
python-multipart==0.0.9
pydantic==2.7.4
requests==2.32.3
twilio==9.1.1
openai==1.35.7
pillow==10.3.0
python-dotenv==1.0.1
aiofiles==24.1.0
pytest==8.2.2
httpx==0.27.0
"""

FILES[".env"] = """OPENAI_API_KEY=your_openai_api_key_here
TWILIO_ACCOUNT_SID=your_twilio_sid_here
TWILIO_AUTH_TOKEN=your_twilio_token_here
PUBLIC_URL=http://localhost:8000
PORT=8000
"""

FILES["tools.py"] = '''import json
from typing import Dict, Any

MARKET_DATABASE: Dict[str, Dict[str, Any]] = {
    "cassava": {"unit": "100kg bag", "price_ghs": 320.00, "market": "Techiman", "trend": "rising"},
    "maize": {"unit": "50kg bag", "price_ghs": 240.00, "market": "Kumasi Central", "trend": "stable"},
    "tomato": {"unit": "crate (medium)", "price_ghs": 450.00, "market": "Agbogbloshie", "trend": "volatile"},
    "cocoa": {"unit": "64kg bag", "price_ghs": 1300.00, "market": "COCOBOD Shed", "trend": "fixed"},
    "yam": {"unit": "100 tubers", "price_ghs": 1100.00, "market": "Ejura", "trend": "falling"},
}

AGRO_INVENTORY: Dict[str, Dict[str, Any]] = {
    "fall_armyworm": {
        "organic": "Neem seed aqueous extract (50g crushed neem seed per 1L water; spray at dawn or dusk)",
        "commercial": "Emamectin benzoate (5% WDG) or Chlorantraniliprole 20% SC",
        "retail_cost_ghs": 45.00,
        "prevention": "Intercrop maize with silverleaf desmodium (push-pull strategy)."
    },
    "cassava_mosaic": {
        "organic": "Immediate rogueing: Uproot and burn infected plants; sanitize machetes with bleach solution",
        "commercial": "Whitefly vector knockdown: Acetamiprid 20% SP",
        "retail_cost_ghs": 55.00,
        "prevention": "Plant certified disease-resistant stems (e.g., Bankye Hemaa / Otuhia varieties)."
    },
    "blight": {
        "organic": "Foliar wood ash suspension (1 cup wood ash filtered in 5L water) or copper soap spray",
        "commercial": "Mancozeb 80% WP or Metalaxyl-M systemic fungicide",
        "retail_cost_ghs": 60.00,
        "prevention": "Prune lower leaves touching wet soil; avoid overhead sprinkler watering."
    },
}

def query_market_prices(crop_name: str) -> str:
    """Fetch commodity spot price, market location, and commercial advice."""
    crop = crop_name.lower().strip()
    data = MARKET_DATABASE.get(crop)
    if data:
        return json.dumps({
            "status": "success",
            "crop": crop,
            "unit": data["unit"],
            "current_price": f"GHS {data['price_ghs']:.2f}",
            "market": data["market"],
            "trend": data["trend"],
            "recommendation": "Sell immediately to capture peak price" if data["trend"] == "rising" else "Store securely if moisture content < 13%"
        })
    return json.dumps({
        "status": "not_found", 
        "message": f"No active bid records found for '{crop_name}'. Available: {list(MARKET_DATABASE.keys())}"
    })

def query_treatment_plan(pest_or_disease: str) -> str:
    """Retrieve verified low-cost organic remedy, chemical alternative, and retail price."""
    key = pest_or_disease.lower().replace(" ", "_").strip()
    remedy = AGRO_INVENTORY.get(key)
    if remedy:
        return json.dumps({
            "status": "success",
            "condition": pest_or_disease,
            "organic_remedy": remedy["organic"],
            "commercial_remedy": remedy["commercial"],
            "retail_cost": f"GHS {remedy['retail_cost_ghs']:.2f}",
            "preventative_measure": remedy["prevention"],
            "hub": "Nearest Regional Agro-Cooperative"
        })
    return json.dumps({
        "status": "general_advisory",
        "condition": pest_or_disease,
        "guidance": "Isolate the damaged crops, avoid overwatering, and bring a leaf sample to the nearest MOFA Extension Officer."
    })
'''

FILES["audio_service.py"] = '''import os
import io
import uuid
from pathlib import Path
import requests
from requests.auth import HTTPBasicAuth
from openai import OpenAI

AUDIO_DIR = Path("./static/audio")
AUDIO_DIR.mkdir(parents=True, exist_ok=True)

def get_openai_client():
    return OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

def transcribe_audio_stream(media_url: str, content_type: str) -> str:
    """Downloads audio from Twilio and executes Whisper transcription."""
    sid = os.getenv("TWILIO_ACCOUNT_SID")
    token = os.getenv("TWILIO_AUTH_TOKEN")
    auth = HTTPBasicAuth(sid, token) if (sid and token) else None

    resp = requests.get(media_url, auth=auth, stream=True, timeout=20)
    resp.raise_for_status()

    ext = "ogg"
    if "mp3" in content_type:
        ext = "mp3"
    elif "wav" in content_type:
        ext = "wav"
    elif "m4a" in content_type or "mp4" in content_type:
        ext = "m4a"

    audio_buf = io.BytesIO(resp.content)
    audio_buf.name = f"voice_input.{ext}"

    client = get_openai_client()
    transcription = client.audio.transcriptions.create(
        model="whisper-1",
        file=audio_buf,
        prompt="Agricultural consultation: crops, diseases, pests, fertilizers, and market prices in Ghana."
    )
    return transcription.text

def generate_voice_response(text: str) -> str:
    """Converts LLM output into an MP3 file via OpenAI TTS."""
    clean_text = text.replace("*", "").replace("#", "").replace("-", " ").strip()[:500]
    filename = f"reply_{uuid.uuid4().hex[:8]}.mp3"
    filepath = AUDIO_DIR / filename

    client = get_openai_client()
    response = client.audio.speech.create(
        model="tts-1",
        voice="onyx",
        input=clean_text
    )
    response.stream_to_file(filepath)
    return f"/static/audio/{filename}"
'''

FILES["agent.py"] = '''import os
import json
from openai import OpenAI
from tools import query_market_prices, query_treatment_plan

TOOL_SPECS = [
    {
        "type": "function",
        "function": {
            "name": "query_market_prices",
            "description": "Fetch real-time commodity spot prices, local market locations, and sell/hold recommendations.",
            "parameters": {
                "type": "object",
                "properties": {
                    "crop_name": {"type": "string", "description": "e.g., maize, cassava, tomato, cocoa, yam"}
                },
                "required": ["crop_name"]
            }
        }
    },
    {
        "type": "function",
        "function": {
            "name": "query_treatment_plan",
            "description": "Lookup validated organic recipes, commercial pesticides, and retail costs for a crop problem.",
            "parameters": {
                "type": "object",
                "properties": {
                    "pest_or_disease": {"type": "string", "description": "e.g., fall_armyworm, cassava_mosaic, blight"}
                },
                "required": ["pest_or_disease"]
            }
        }
    }
]

SYSTEM_PROMPT = """You are FarmVoice AI, an autonomous, highly practical agricultural specialist for smallholder farmers.
Strict Guidelines:
1. When analyzing plant symptoms or an image:
   - Identify the primary visible symptom.
   - Name the exact disease or pest.
   - ALWAYS invoke the query_treatment_plan tool if an ailment is detected.
2. When market prices or selling timing are requested:
   - ALWAYS call the query_market_prices tool.
3. Keep instructions direct, human, and actionable:
   - Prioritize inexpensive organic homemade remedies first.
   - Mention the retail cost in Cedis (GHS) if commercial treatment is needed.
   - Avoid lengthy academic theory. Give farmers step-by-step instructions.
"""

def run_farmer_agent(user_message: str, image_url: str = None) -> str:
    client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))
    messages = [{"role": "system", "content": SYSTEM_PROMPT}]

    user_payload = []
    if user_message:
        user_payload.append({"type": "text", "text": user_message})
    if image_url:
        user_payload.append({"type": "image_url", "image_url": {"url": image_url}})

    messages.append({"role": "user", "content": user_payload if image_url else user_message})

    response = client.chat.completions.create(
        model="gpt-4o",
        messages=messages,
        tools=TOOL_SPECS,
        tool_choice="auto"
    )

    msg = response.choices[0].message

    # Execute tools autonomously if requested by the model
    if msg.tool_calls:
        messages.append(msg)
        for call in msg.tool_calls:
            name = call.function.name
            args = json.loads(call.function.arguments)

            if name == "query_market_prices":
                result = query_market_prices(args.get("crop_name", ""))
            elif name == "query_treatment_plan":
                result = query_treatment_plan(args.get("pest_or_disease", ""))
            else:
                result = "{}"

            messages.append({
                "role": "tool",
                "tool_call_id": call.id,
                "content": result
            })

        final_response = client.chat.completions.create(
            model="gpt-4o",
            messages=messages
        )
        return final_response.choices[0].message.content

    return msg.content
'''

FILES["main.py"] = '''import os
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
'''

FILES["static/index.html"] = '''<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>FarmVoice AI | Field Terminal</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-stone-900 text-stone-100 min-h-screen p-4 flex flex-col items-center justify-center">
  <div class="max-w-2xl w-full bg-stone-800 border border-stone-700 rounded-2xl p-6 shadow-2xl space-y-5">
    <div class="border-b border-stone-700 pb-4 flex justify-between items-center">
      <div>
        <h1 class="text-2xl font-black text-emerald-400">🌾 FarmVoice AI</h1>
        <p class="text-xs text-stone-400">Autonomous Agricultural Field Agent</p>
      </div>
      <span class="text-xs bg-emerald-950 text-emerald-300 border border-emerald-800 px-3 py-1 rounded-full font-mono">ONLINE</span>
    </div>

    <div class="space-y-3">
      <label class="block text-sm font-semibold text-stone-300">Farmer Inquiry (Text or Voice Transcribed)</label>
      <textarea id="promptInput" rows="3" class="w-full bg-stone-950 border border-stone-700 rounded-lg p-3 text-sm focus:outline-emerald-500 text-stone-100" placeholder="e.g., My maize plants have caterpillars and holes in the leaves. Also, how much is maize selling for in Kumasi?"></textarea>
      
      <div>
        <label class="block text-xs font-semibold text-stone-400 mb-1">Optional Leaf Photo (Visual Pathology)</label>
        <input type="file" id="imageInput" accept="image/*" class="text-xs text-stone-400 file:mr-4 file:py-2 file:px-4 file:rounded-lg file:border-0 file:text-xs file:font-semibold file:bg-stone-700 file:text-stone-200 hover:file:bg-stone-600"/>
      </div>
    </div>

    <button id="sendBtn" onclick="submitInquiry()" class="w-full bg-emerald-600 hover:bg-emerald-500 text-white font-bold py-3 rounded-lg transition duration-200">
      Run Autonomous Agent
    </button>

    <div id="loader" class="hidden text-center py-4">
      <p class="text-sm font-semibold text-emerald-400 animate-pulse">Running GPT-4o Multimodal Agent & Tool Calling...</p>
    </div>

    <div id="resultBox" class="hidden bg-stone-950 border border-stone-800 rounded-xl p-4 space-y-3">
      <h3 class="text-xs font-mono font-bold text-emerald-400 uppercase tracking-wide">Autonomous Output</h3>
      <div id="outputText" class="text-sm text-stone-200 whitespace-pre-line leading-relaxed"></div>
      <div id="audioPlayerContainer" class="pt-2"></div>
    </div>
  </div>

  <script>
    async function submitInquiry() {
      const text = document.getElementById("promptInput").value;
      const fileInput = document.getElementById("imageInput");
      if (!text && fileInput.files.length === 0) return alert("Enter a prompt or choose a photo.");

      document.getElementById("loader").classList.remove("hidden");
      document.getElementById("resultBox").classList.add("hidden");

      const fd = new FormData();
      fd.append("text", text);
      if (fileInput.files.length > 0) {
        fd.append("file", fileInput.files[0]);
      }

      try {
        const res = await fetch("/api/diagnose", { method: "POST", body: fd });
        const data = await res.json();
        
        document.getElementById("outputText").innerText = data.text_response;
        const container = document.getElementById("audioPlayerContainer");
        if (data.audio_url) {
          container.innerHTML = `<label class="text-xs font-semibold text-stone-400 block mb-1">Generated Spoken Voice Output:</label><audio controls class="w-full"><source src="${data.audio_url}" type="audio/mpeg"></audio>`;
        } else {
          container.innerHTML = "";
        }
        document.getElementById("resultBox").classList.remove("hidden");
      } catch (err) {
        alert("Execution error. Verify backend is running and API key is set.");
      } finally {
        document.getElementById("loader").classList.add("hidden");
      }
    }
  </script>
</body>
</html>
'''

FILES["test_system.py"] = '''import pytest
from tools import query_market_prices, query_treatment_plan
from fastapi.testclient import TestClient
from main import app

client = TestClient(app)

def test_health_check():
    response = client.get("/health")
    assert response.status_code == 200
    assert response.json()["status"] == "healthy"

def test_market_tool_known():
    result = query_market_prices("maize")
    assert "Kumasi" in result
    assert "GHS 240.00" in result

def test_market_tool_unknown():
    result = query_market_prices("nonexistent_crop")
    assert "not_found" in result

def test_remedy_tool_fall_armyworm():
    result = query_treatment_plan("fall_armyworm")
    assert "Neem seed" in result
    assert "45.00" in result

def test_whatsapp_empty_ping():
    response = client.post("/webhook/whatsapp", data={"Body": ""})
    assert response.status_code == 200
    assert "FarmVoice AI Ready" in response.text
'''

FILES["Dockerfile"] = """FROM python:3.11-slim
WORKDIR /app
RUN apt-get update && apt-get install -y ffmpeg curl && rm -rf /var/lib/apt/lists/*
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY . .
EXPOSE 8000
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
"""

FILES["docker-compose.yml"] = """version: '3.8'
services:
  farmvoice-ai:
    build: .
    ports:
      - "8000:8000"
    env_file:
      - .env
    volumes:
      - ./static/audio:/app/static/audio
      - ./static/uploads:/app/static/uploads
    restart: unless-stopped
"""

def build_project():
    print("Building FarmVoice AI production system...")
    for path_str, content in FILES.items():
        file_path = Path(path_str)
        file_path.parent.mkdir(parents=True, exist_ok=True)
        with open(file_path, "w", encoding="utf-8") as f:
            f.write(content)
        print(f"Created: {path_str}")
    print("\nProject build complete.")

if __name__ == "__main__":
    build_project()