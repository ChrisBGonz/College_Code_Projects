#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import os
import time
from google import genai

# --- CONFIGURATION ---
OUTPUT_DIR = "/Users/christophergonzalez/Desktop/Gemini_Codes"
API_KEY = "Gemini_API_Key_Here"
MODEL = "gemini-3-flash-preview"

client = genai.Client(api_key=API_KEY)

def save_code(content, language, prompt_type, prompt_num):
    folder_path = os.path.join(OUTPUT_DIR, language, prompt_type)
    os.makedirs(folder_path, exist_ok=True)
    file_name = f"prompt_{prompt_num}.txt"
    full_path = os.path.join(folder_path, file_name)
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(content)

def get_ai_response_with_retry(prompt):
    """
    Sends a prompt to Gemini and retries indefinitely on 503/Overloaded errors.
    """
    delay = 2  
    max_delay = 60 
    
    while True:
        try:
            response = client.models.generate_content(
                model=MODEL,
                contents=prompt,
                config={
                    'system_instruction': "Provide the source code for the following request. Do not include any text, explanations, or markdown formatting in your response. Output the raw code only.",
                    'temperature': 0.2
                }
            )
            return response.text
        
        except Exception as e:
            error_msg = str(e)
            # Check for 'Model Overloaded' errors
            if "503" in error_msg or "overloaded" in error_msg.lower():
                print(f"Server Busy (503). Retrying in {delay}s... Error: {error_msg}")
                time.sleep(delay)
                # Increase delay exponentially for the next attempt
                delay = min(delay * 2, max_delay)
            else:
                print(f"Permanent Gemini API Error: {e}")
                return None

def main():
    df = pd.read_csv("Updated_AI_Generated_Code_Analysis.csv")
    print(f"Starting Gemini automation. Saving to: {OUTPUT_DIR}")

    for index, row in df.iterrows():
        prompt_num = (index // 8) + 1
        language = row['Language']
        
        # Process Literal Translation
        print(f"Processing Prompt {prompt_num} [{language}] - Literal...")
        code_lit = get_ai_response_with_retry(row['Prompt (Literal Translation)'])
        if code_lit: 
            save_code(code_lit, language, "Literal", prompt_num)
            
        # Process Natural Phrasing Translation
        print(f"Processing Prompt {prompt_num} [{language}] - Natural...")
        code_nat = get_ai_response_with_retry(row['Prompt (Natural Developer Phrasing Translation)'])
        if code_nat: 
            save_code(code_nat, language, "Natural", prompt_num)

        time.sleep(0.5) 

if __name__ == "__main__":
    main()

