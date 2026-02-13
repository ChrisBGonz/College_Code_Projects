#!/usr/bin/env python
# coding: utf-8

# In[2]:


import pandas as pd 
import time
import os
from openai import OpenAI 

# 1. Setup
client = OpenAI(api_key="Enter-API-Key-Here")

def get_translation(prompt, target_lang, style):
    # Logic for literal vs natural
    if style == "literal":
        if target_lang.lower() == 'english': return prompt
        system_msg = f"Translate this coding prompt literally and formally into {target_lang}."
    else:
        system_msg = f"Rephrase this prompt into {target_lang} using natural developer phrasing and technical industry shorthand."

    try:
        response = client.chat.completions.create(
            model="gpt-5.2",
            messages=[
                {"role": "system", "content": system_msg},
                {"role": "user", "content": prompt}
            ],
            temperature=0
        )
        return response.choices[0].message.content.strip()
    except Exception as e:
        return f"Error: {e}"

# 2. Load File
df = pd.read_csv('AI_Generated_Code_Analysis.csv')

# Removes extra 'Unnamed' columns to keep the file size small
df = df.loc[:, ~df.columns.str.contains('^Unnamed')]

# 3. Process in-place to keep original formatting
current_active_prompt = None

print("Starting translations...")

for index, row in df.iterrows():
    # Detects when code reaches a new 'Parent' prompt
    if pd.notna(row['Original Prompt']):
        current_active_prompt = row['Original Prompt']
    
    # Skip rows that don't have a prompt or a language
    if not current_active_prompt or pd.isna(row['Language']):
        continue

    target_lang = row['Language']
    print(f"Row {index}: Processing {target_lang}...")

    # Fill Columns C and D
    df.at[index, 'Prompt (Literal Translation)'] = get_translation(current_active_prompt, target_lang, "literal")
    df.at[index, 'Prompt (Natural Developer Phrasing Translation)'] = get_translation(current_active_prompt, target_lang, "natural")
    
    # API safety pause
    time.sleep(0.1)

# 4. Save as new file
df.to_csv('Updated_AI_Generated_Code_Analysis.csv', index=False)
print("\nDone! Your translations has been preserved in the new file.")

