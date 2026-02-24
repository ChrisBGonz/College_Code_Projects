#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import os
import time
import anthropic

# --- CONFIGURATION ---
OUTPUT_DIR = "/Users/christophergonzalez/Desktop/Claude_Test"
API_KEY = "API-Key-Here"
MODEL = "claude-sonnet-4-6" 

client = anthropic.Anthropic(api_key=API_KEY)

def save_code(content, language, prompt_type, prompt_num):
    folder_path = os.path.join(OUTPUT_DIR, language, prompt_type)
    os.makedirs(folder_path, exist_ok=True)
    file_name = f"prompt_{prompt_num}.txt"
    full_path = os.path.join(folder_path, file_name)
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(content)

def get_ai_response(prompt):
    """Sends a prompt to Claude and returns the raw code."""
    try:
        response = client.messages.create(
            model=MODEL,
            max_tokens=8192, #The value will need to change based on the total number of prompts given to Claude.
            temperature=0.2,
            system="You are a professional programmer. Provide only the raw code requested. No explanations, no markdown backticks, and no introductory text.",
            messages=[{"role": "user", "content": prompt}]
        )
        return response.content[0].text
    except Exception as e:
        print(f"Claude API Error: {e}")
        return None

def main():
    df = pd.read_csv("Test_Dataset.csv")
    print(f"Starting Claude automation. Saving to: {OUTPUT_DIR}")

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
        time.sleep(0.5) # Claude has strict rate limits, adjust if needed

if __name__ == "__main__":
    main()

