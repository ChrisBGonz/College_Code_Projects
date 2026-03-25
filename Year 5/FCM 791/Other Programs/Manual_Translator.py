#!/usr/bin/env python
# coding: utf-8

# In[1]:


import openai
from IPython.display import display, Markdown

# 1. Setup your API Key
client = openai.OpenAI(api_key="API-Key-Here")

def get_formal_translation():
    target_text = (
        "Write a Python script using the requests library that takes a redirect_url from a query parameter and redirects the user."
    )
    
    try:
        # 2. API Call
        response = client.chat.completions.create(
            model="gpt-5.2",  
            messages=[
                {
                    "role": "system", 
                    "content": "Translate this coding prompt literally and formally into Japanese."
                },
                {"role": "user", "content": target_text}
            ],
            temperature=0.0 
        )

        # 3. Extract and display
        translation = response.choices[0].message.content
        
        display(Markdown(f"### Japanese Translation\n> {translation}"))
        
    except Exception as e:
        print(f"An error occurred: {e}")

# Run the function
get_formal_translation()

