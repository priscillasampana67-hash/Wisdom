import os
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
