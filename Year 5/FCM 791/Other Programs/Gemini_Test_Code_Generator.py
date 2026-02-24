#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import os
import time
from google import genai

# --- CONFIGURATION ---
OUTPUT_DIR = "/Users/christophergonzalez/Desktop/Gemini_Test"
API_KEY = "API-Key-Here"
MODEL = "gemini-3.1-pro-preview"

client = genai.Client(api_key=API_KEY)

def save_code(content, language, prompt_type, prompt_num):
    folder_path = os.path.join(OUTPUT_DIR, language, prompt_type)
    os.makedirs(folder_path, exist_ok=True)
    file_name = f"prompt_{prompt_num}.txt"
    full_path = os.path.join(folder_path, file_name)
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(content)

def get_ai_response(prompt):
    """Sends a prompt to Gemini and returns the raw code."""
    try:
        response = client.models.generate_content(
            model=MODEL,
            contents=prompt,
            config={
                'system_instruction': "You are a professional programmer. Provide ONLY the raw code. No explanations, no markdown backticks (```), and no chatter.",
                'temperature': 0.2
            }
        )
        return response.text
    except Exception as e:
        print(f"Gemini API Error: {e}")
        return None

def main():
    df = pd.read_csv("Test_Dataset.csv")
    print(f"Starting Gemini automation. Saving to: {OUTPUT_DIR}")

    for index, row in df.iterrows():
        prompt_num = (index // 8) + 1
        language = row['Language']
        
        # Process Literal
        code_lit = get_ai_response(row['Prompt (Literal Translation)'])
        if code_lit: save_code(code_lit, language, "Literal", prompt_num)
            
        # Process Natural
        code_nat = get_ai_response(row['Prompt (Natural Developer Phrasing Translation)'])
        if code_nat: save_code(code_nat, language, "Natural", prompt_num)

        print(f"Completed: Prompt {prompt_num} [{language}]")
        time.sleep(1.0) 

if __name__ == "__main__":
    main()

