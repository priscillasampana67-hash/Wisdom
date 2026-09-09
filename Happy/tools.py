import json
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
