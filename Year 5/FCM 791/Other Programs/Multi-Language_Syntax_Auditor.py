#!/usr/bin/env python
# coding: utf-8

# In[2]:


import os
import csv
import ast
import re

# Configuration
ROOT_DIR = '/Users/christophergonzalez/Desktop/ChatGPT_Codes'
PROMPT_DATA_CSV = 'Updated_AI_Generated_Code_Analysis.csv'

LANGUAGES = ['Chinese (Simplified)', 'English', 'German', 'Hindi', 'Japanese', 'Portuguese', 'Russian', 'Spanish']
SUB_FOLDERS = ['Literal', 'Natural']
OUTPUT_FILE = 'Syntax_Audit_Results.csv'

def check_python_syntax(code):
    """Uses AST to check syntax with high tolerance for snippets."""
    code_clean = code.strip()
    try:
        ast.parse(code_clean)
        return True, "Valid Python Syntax"
    except SyntaxError:
        try:
            wrapped = f"def __wrapper__():\n" + "\n".join(["    " + line for line in code_clean.splitlines()])
            ast.parse(wrapped)
            return True, "Valid Python Snippet (Functional)"
        except SyntaxError as e:
            return False, f"Python Syntax Error: {e.msg}"

def check_brace_balance(code):
    """Checks for balanced structural characters with a focus on code logic."""
    temp_code = re.sub(r'(".*?"|\'.*?\')', '', code)
    braces = temp_code.count('{') - temp_code.count('}')
    parens = temp_code.count('(') - temp_code.count(')')
    brackets = temp_code.count('[') - temp_code.count(']')
    
    if braces == 0 and parens == 0 and brackets == 0:
        return True, "Balanced Structure"
    
    errors = []
    if braces != 0: errors.append(f"Braces:{braces}")
    if parens != 0: errors.append(f"Parens:{parens}")
    if brackets != 0: errors.append(f"Brackets:{brackets}")
    return False, f"Unbalanced: " + ", ".join(errors)

def detect_and_verify(code, prompt_hint=""):
    """
    Highly generalized detection. If the forced language fails, 
    it falls back to structural validation rather than marking as FAIL.
    """
    code_strip = code.strip()
    if not code_strip:
        return "Empty", "FAIL", "File is empty"

    hint = prompt_hint.lower()
    
    # 1. PYTHON CHECK
    is_python_hint = any(x in hint for x in ["python", "flask", "django", "pandas", "pip"])
    if is_python_hint or "def " in code or "import " in code:
        passed, msg = check_python_syntax(code)
        if passed:
            return "Python", "PASS", msg

    # 2. C-STYLE / BRACE CHECK (JS, Java, C, C++, PHP, CSS)
    is_brace_hint = any(x in hint for x in ["java", "javascript", "script", " c ", "c++", "php", "css"])
    if is_brace_hint or "{" in code:
        passed, msg = check_brace_balance(code)
        label = "C-Style/Brace"
        if "javascript" in hint or "function" in code: label = "JavaScript"
        elif "java" in hint: label = "Java"
        elif "<?php" in code: label = "PHP"
        
        if passed: return label, "PASS", msg
        if is_brace_hint: return label, "FAIL", msg

    # 3. RUBY CHECK
    if "ruby" in hint or ("def " in code and "end" in code):
        ends = code.count("end")
        defs = code.count("def ") + code.count("class ")
        if ends >= defs and defs > 0:
            return "Ruby", "PASS", "Valid Ruby blocks"

    # 4. DATA/QUERY CHECK
    if "sql" in hint or any(x in code.upper() for x in ["SELECT ", "CREATE TABLE", "INSERT INTO"]):
        return "SQL", "PASS", "SQL Keywords detected"
    
    if (code_strip.startswith("{") and code_strip.endswith("}")) or "json" in hint:
        return "JSON/Config", "PASS", "Data structure detected"

    # 5. GENERALIZED LOGIC FALLBACK
    # If it contains common programming markers (assignment, logic, calls)
    logic_patterns = [r'\w+\s*=', r'\w+\(.*\)', r'if\s*\(', r'for\s*\(', r'while\s*\(', r'return\s+']
    if any(re.search(p, code) for p in logic_patterns):
        passed, msg = check_brace_balance(code)
        return "Generic Snippet", ("PASS" if passed else "FAIL"), "Validated via structural balance"

    return "Unknown", "FAIL", "No recognizable code or logic patterns"

def load_prompt_hints():
    hints = {}
    if os.path.exists(PROMPT_DATA_CSV):
        try:
            with open(PROMPT_DATA_CSV, 'r', encoding='utf-8') as f:
                reader = csv.reader(f)
                next(reader)
                for i, row in enumerate(reader, 1):
                    hints[i] = row[0]
        except Exception: pass
    return hints

def main():
    report = []
    prompt_hints = load_prompt_hints()
    
    print(f"Starting Generalized Audit on: {os.path.abspath(ROOT_DIR)}")

    for lg in LANGUAGES:
        for style in SUB_FOLDERS:
            folder_path = os.path.join(ROOT_DIR, lg, style)
            if not os.path.exists(folder_path): continue
            
            print(f"Processing: {lg} -> {style}")
            for i in range(1, 101):
                file_name = f"prompt_{i}.txt"
                file_path = os.path.join(folder_path, file_name)
                
                if os.path.exists(file_path):
                    hint = prompt_hints.get(i, "")
                    with open(file_path, 'r', encoding='utf-8', errors='replace') as f:
                        content = f.read()
                    
                    det_lang, status, detail = detect_and_verify(content, hint)
                    report.append({
                        'Language_Group': lg, 'Style': style, 'File': file_name,
                        'Detected_Lang': det_lang, 'Status': status, 'Details': detail
                    })

    if report:
        with open(OUTPUT_FILE, 'w', newline='', encoding='utf-8') as f:
            writer = csv.DictWriter(f, fieldnames=report[0].keys())
            writer.writeheader()
            writer.writerows(report)
        print(f"Audit Complete. Results saved to {OUTPUT_FILE}")

if __name__ == "__main__":
    main()

