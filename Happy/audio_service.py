import os
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
