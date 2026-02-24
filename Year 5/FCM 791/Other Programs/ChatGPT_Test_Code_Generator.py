#!/usr/bin/env python
# coding: utf-8

# In[4]:


import pandas as pd
import os
import time
from openai import OpenAI

OUTPUT_DIR = "/Users/christophergonzalez/Desktop/ChatGPT_Test"
CSV_FILE = "Test_Dataset.csv"
MODEL = "gpt-5.2-codex"

client = OpenAI(api_key="API-Key-Here")

#Function to save files that will be created
def save_code(content, language, prompt_type, prompt_num):
    """
    Saves the AI-generated code into a structured folder layout:
    OUTPUT_DIR / Language / PromptType / prompt_X.txt
    """
    folder_path = os.path.join(OUTPUT_DIR, language, prompt_type)
    os.makedirs(folder_path, exist_ok=True)

    file_name = f"prompt_{prompt_num}.txt"
    full_path = os.path.join(folder_path, file_name)

    with open(full_path, "w", encoding="utf-8") as f:
        f.write(content)


#Function to feed the prompts to ChatGPT
def get_ai_response(prompt):
    """
    Sends a prompt to GPT-5.2-Codex using the Responses API
    and returns raw code only.
    """
    try:
        response = client.responses.create(
            model=MODEL,
            input=(
                "You are a professional software developer.\n"
                "Return ONLY the requested source code.\n"
                "Do NOT include explanations, comments, or markdown formatting.\n\n"
                f"{prompt}"
            ),
            reasoning={"effort": "high"}
        )

        return response.output_text

    except Exception as e:
        print(f"Error fetching response: {e}")
        return None

def main():
    if not os.path.exists(CSV_FILE):
        print(f"ERROR: Could not find '{CSV_FILE}'.")
        return

    df = pd.read_csv(CSV_FILE)

    print("========================================")
    print(" Starting GPT-5.2-Codex Code Generation ")
    print(f" Output directory: {OUTPUT_DIR}")
    print("========================================\n")

    for index, row in df.iterrows():
        # Each group of 8 rows = one logical prompt
        prompt_num = (index // 8) + 1

        language = row["Language"]
        literal_prompt = row["Prompt (Literal Translation)"]
        natural_prompt = row["Prompt (Natural Developer Phrasing Translation)"]

        print(f"Processing Prompt {prompt_num} | Language: {language}")

        # ---- Literal Prompt ----
        literal_code = get_ai_response(literal_prompt)
        if literal_code:
            save_code(literal_code, language, "Literal", prompt_num)

        # ---- Natural Prompt ----
        natural_code = get_ai_response(natural_prompt)
        if natural_code:
            save_code(natural_code, language, "Natural", prompt_num)

        # Small delay to avoid rate limits
        time.sleep(0.5)

    print("\n✅ SUCCESS: All prompts processed and saved.")

if __name__ == "__main__":
    main()

