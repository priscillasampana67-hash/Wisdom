import pytest
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
