#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

# Setting visual style for plots
sns.set_theme(style="whitegrid")

file_list = [
    "ChatGPT_Code_Evaluation_By_ChatGPT.csv",
    "ChatGPT_Code_Evaluation_By_Claude.csv",
    "ChatGPT_Code_Evaluation_By_Gemini.csv",
    "Claude_Code_Evaluation_By_ChatGPT.csv",
    "Claude_Code_Evaluation_By_Claude.csv",
    "Claude_Code_Evaluation_By_Gemini.csv",
    "Gemini_Code_Evaluation_By_ChatGPT.csv",
    "Gemini_Code_Evaluation_By_Claude.csv",
    "Gemini_Code_Evaluation_By_Gemini.csv",
]


# In[2]:


all_dfs = []

for file in file_list:
    if os.path.exists(file):
        df = pd.read_csv(file)
        parts = file.replace('.csv', '').split('_Code_Evaluation_By_')
        df['Generator'] = parts[0]
        df['Evaluator'] = parts[1]
        all_dfs.append(df)

combined_df = pd.concat(all_dfs, ignore_index=True)

# Previewing the combined data
print(f"Total rows loaded: {len(combined_df)}")
combined_df.head()


# In[3]:


# Basic statistics for Correctness_Score
correctness_summary = combined_df.groupby('Generator')[['Correctness_Score']].agg(['mean', 'median', 'std'])
print("Basic Statistics for Correctnes Scores")
display(correctness_summary)

# Basic statistics for Security_Score
security_summary = combined_df.groupby('Generator')[['Security_Score']].agg(['mean', 'median', 'std'])
print("\nBasic Statistics for Security Scores")
display(security_summary)


# In[4]:


#Visualizing average correctness scores and security scores
avg_scores = combined_df.groupby(['Generator', 'Evaluator'])[['Correctness_Score', 'Security_Score']].mean().reset_index()

fig, axes = plt.subplots(1, 2, figsize=(16, 7))

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Plotting correctness
sns.barplot(data=avg_scores, x='Generator', y='Correctness_Score', hue='Evaluator', palette=colors, ax=axes[0])
axes[0].set_title('Avg Correctness Score')
axes[0].set_ylim(0, 110)

# Adding labels to correctness bars
for container in axes[0].containers:
    axes[0].bar_label(container, fmt='%.1f', padding=3)

# Plotting security
sns.barplot(data=avg_scores, x='Generator', y='Security_Score', hue='Evaluator', palette=colors, ax=axes[1])
axes[1].set_title('Avg Security Score')
axes[1].set_ylim(0, 110)

# Adding labels to security bars
for container in axes[1].containers:
    axes[1].bar_label(container, fmt='%.1f', padding=3)

plt.tight_layout()
plt.show()


# In[5]:


# Expressing average correctness scores (Generator vs. Evaluator) in a table
correctness_pivot = combined_df.pivot_table(
    index='Generator', 
    columns='Evaluator', 
    values='Correctness_Score', 
    aggfunc='mean'
).round(1)

# Expressing average security scores (Generator vs. Evaluator) in a table
security_pivot = combined_df.pivot_table(
    index='Generator', 
    columns='Evaluator', 
    values='Security_Score', 
    aggfunc='mean'
).round(1)

print("Average Correctness Scores (Generator vs. Evaluator)")
display(correctness_pivot)

print("\nAverage Security Scores (Generator vs. Evaluator)")
display(security_pivot)


# In[6]:


# Creating a heatmap of average correctness scores
pivot_sec = avg_scores.pivot(index='Generator', columns='Evaluator', values='Correctness_Score')

plt.figure(figsize=(8, 6))
sns.heatmap(pivot_sec, annot=True, cmap='YlOrRd', fmt=".1f")
plt.title('Heatmap: Average Correctness Scores (Rows=Generator, Cols=Evaluator)')
plt.show()


# In[7]:


# Creating a heatmap of average security scores
pivot_sec = avg_scores.pivot(index='Generator', columns='Evaluator', values='Security_Score')

plt.figure(figsize=(8, 6))
sns.heatmap(pivot_sec, annot=True, cmap='YlOrRd', fmt=".1f")
plt.title('Heatmap: Average Security Scores (Rows=Generator, Cols=Evaluator)')
plt.show()


# In[8]:


# Behavior of the models as evaluators (Strictness vs. Leniency)
print("\nEvaluator Behavior (Average Scores Given)")
eval_stats = combined_df.groupby('Evaluator')[['Correctness_Score', 'Security_Score']].mean()
display(eval_stats)


# In[9]:


# Checking for signs of self-bias in correctness scores
combined_df['Is_Self_Evaluation'] = combined_df['Generator'] == combined_df['Evaluator']

bias_analysis = combined_df.groupby(['Evaluator', 'Is_Self_Evaluation'])[['Correctness_Score', 'Security_Score']].mean().reset_index()

bias_pivot = bias_analysis.pivot(index='Evaluator', columns='Is_Self_Evaluation', values='Correctness_Score')
bias_pivot.columns = ['Avg_Score_Given_to_Others', 'Avg_Score_Given_to_Self']
bias_pivot['Bias_Gap'] = bias_pivot['Avg_Score_Given_to_Self'] - bias_pivot['Avg_Score_Given_to_Others']

print("Self-Bias Analysis (Correctness Scores)")
display(bias_pivot)

# Checking for signs of self-bias in security scores
combined_df['Is_Self_Evaluation'] = combined_df['Generator'] == combined_df['Evaluator']

bias_analysis = combined_df.groupby(['Evaluator', 'Is_Self_Evaluation'])[['Correctness_Score', 'Security_Score']].mean().reset_index()

bias_pivot = bias_analysis.pivot(index='Evaluator', columns='Is_Self_Evaluation', values='Security_Score')
bias_pivot.columns = ['Avg_Score_Given_to_Others', 'Avg_Score_Given_to_Self']
bias_pivot['Bias_Gap'] = bias_pivot['Avg_Score_Given_to_Self'] - bias_pivot['Avg_Score_Given_to_Others']

print("\nSelf-Bias Analysis (Security Scores)")
display(bias_pivot)


# In[10]:


# Identifying which OWASP Category was the most promiment in evaluation
plt.figure(figsize=(12, 8))

# Getting the order
owasp_counts = combined_df['OWASP_Category'].value_counts()
owasp_order = owasp_counts.index

# Creating the plot
ax = sns.countplot(
    data=combined_df, 
    y='OWASP_Category', 
    order=owasp_order, 
    hue='OWASP_Category', 
    palette='magma', 
    legend=False
)

# Looping through all containers to label every bar
for container in ax.containers:
    ax.bar_label(container, fmt='%d', padding=5)

# Visualizing
plt.title('Exact Counts of OWASP Security Categories Identified')
plt.xlabel('Number of Occurrences')
plt.ylabel('OWASP Category')
plt.tight_layout()
plt.show()


# In[11]:


# Identifying which OWASP Category was the most promiment in evaluation (by the evaluator)
plt.figure(figsize=(12, 15))

owasp_order = combined_df['OWASP_Category'].value_counts().index

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Creating a grouped horizontal bar chart
ax = sns.countplot(
    data=combined_df, 
    y='OWASP_Category', 
    hue='Generator', 
    order=owasp_order, 
    palette=colors
)

# Adding exact numbers to each bar
for container in ax.containers:
    ax.bar_label(container, fmt='%d', padding=5, fontsize=10)

# Visualizing
plt.title('Security Vulnerability Distribution: ChatGPT vs. Claude vs. Gemini', fontsize=16)
plt.xlabel('Number of Occurrences (Total Evaluations)', fontsize=12)
plt.ylabel('OWASP Category', fontsize=12)
plt.legend(title='Generator', loc='lower right')

plt.tight_layout()
plt.show()


# In[12]:


# Creating a table of previous visual
owasp_table = pd.crosstab(combined_df['OWASP_Category'], combined_df['Generator'])

# Sorting by the most common overall vulnerabilities
owasp_table['Total'] = owasp_table.sum(axis=1)
owasp_table = owasp_table.sort_values(by='Total', ascending=False)

display(owasp_table)


# In[13]:


# Identifying the top 10 root causes
top_10_causes = combined_df['Root_Cause'].value_counts().nlargest(10).index
root_cause_subset = combined_df[combined_df['Root_Cause'].isin(top_10_causes)]

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Visualizing the top 10 root causeed (by the AI tool)
plt.figure(figsize=(12, 10))
ax = sns.countplot(
    data=root_cause_subset,
    y='Root_Cause',
    hue='Generator',
    order=top_10_causes,
    palette=colors
)

# Adding labels to every bar in the group
for container in ax.containers:
    ax.bar_label(container, fmt='%d', padding=5)

plt.title('Top 10 Root Causes Split by AI Generator', fontsize=15)
plt.xlabel('Number of Occurrences')
plt.ylabel('Root Cause Category')
plt.legend(title='Generator', loc='lower right')
plt.tight_layout()
plt.show()


# In[14]:


# Expressing the top 10 root causes as a whole
root_causes = combined_df['Root_Cause'].value_counts().head(10)
print("\nTop 10 Root Causes:")
print(root_causes)


# In[15]:


# Calculating correlation of correctness and security for each generator
correlations = []
for gen in ["ChatGPT", "Claude", "Gemini"]:
    subset = combined_df[combined_df['Generator'] == gen]
    r = subset[['Correctness_Score', 'Security_Score']].corr().iloc[0, 1]
    correlations.append({'Generator': gen, 'Correlation': r})

corr_df = pd.DataFrame(correlations)

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Plotting
plt.figure(figsize=(8, 6))
ax = sns.barplot(data=corr_df, x='Generator', y='Correlation', hue='Generator', 
                 palette=colors, legend=False)

# Adding exact labels
for container in ax.containers:
    ax.bar_label(container, fmt='%.3f', padding=3)

plt.title('Pearson Correlation: Correctness vs. Security (By Generator)')
plt.ylabel('Correlation Coefficient (r)')
plt.ylim(0, 0.7)
plt.show()


# In[16]:


# Listing overall average correctness and security scores by the language
lang_stats = combined_df.groupby('Language')[['Correctness_Score', 'Security_Score']].mean()
display(lang_stats.sort_values(by='Security_Score', ascending=False))


# In[17]:


# Visualizing average correctness scores (by the language and AI tool)
plt.figure(figsize=(16, 8))

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Creating the plot
ax = sns.barplot(
    data=combined_df, 
    x='Language', 
    y='Correctness_Score', 
    hue='Generator', 
    palette=colors,
    errorbar=None 
)

# Adding exact numbers on top of each bar
for container in ax.containers:
    ax.bar_label(container, fmt='%.1f', padding=3, fontsize=9)

plt.title('Average Correctness Score by Language and AI Generator', fontsize=16)
plt.ylabel('Average Correctness Score')
plt.xlabel('Prompt Language')
plt.xticks(rotation=45)
plt.ylim(0, 110)
plt.legend(title='Generator', loc='upper right')

plt.tight_layout()
plt.show()


# In[18]:


# Visualizing average security scores (by the language and AI tool)
plt.figure(figsize=(16, 8))

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Creating the plot 
ax = sns.barplot(
    data=combined_df, 
    x='Language', 
    y='Security_Score', 
    hue='Generator', 
    palette=colors,
    errorbar=None 
)

# Adding exact numbers on top of each bar
for container in ax.containers:
    ax.bar_label(container, fmt='%.1f', padding=3, fontsize=9)

plt.title('Average Security Score by Language and AI Generator', fontsize=16)
plt.ylabel('Average Security Score')
plt.xlabel('Prompt Language')
plt.xticks(rotation=45)
plt.ylim(0, 65)
plt.legend(title='Generator', loc='upper right')

plt.tight_layout()
plt.show()


# In[19]:


# Creating a table for correctness scores (by the language and AI tool)
correctness_pivot = combined_df.pivot_table(
    index='Language', 
    columns='Generator', 
    values='Correctness_Score', 
    aggfunc='mean'
)

# Creating a table for Security Scores (by the language and AI tool)
security_pivot = combined_df.pivot_table(
    index='Language', 
    columns='Generator', 
    values='Security_Score', 
    aggfunc='mean'
)

print("Average Correctness Score by Language and AI Tool")
display(correctness_pivot.round(1))

print("\nAverage Security Score by Language and AI Tool")
display(security_pivot.round(1))


# In[20]:


# Creating a heatmap to determine if certain languages are more likely to trigger specific types of OWASP vulnerabilities
lang_owasp_pivot = pd.crosstab(combined_df['Language'], combined_df['OWASP_Category'])

plt.figure(figsize=(14, 8))
sns.heatmap(lang_owasp_pivot, annot=True, fmt='d', cmap='YlOrRd')

plt.title('Heatmap: OWASP Vulnerabilities by Language', fontsize=16)
plt.xlabel('OWASP Category')
plt.ylabel('Prompt Language')

plt.tight_layout()
plt.show()


# In[21]:


# Group the data by translation type and generator
trans_stats = combined_df.groupby(['Translation_Type', 'Generator'])[['Correctness_Score', 'Security_Score']].mean().reset_index()

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Create the plots
fig, axes = plt.subplots(1, 2, figsize=(16, 7))

# Correctness comparison 
sns.barplot(data=trans_stats, x='Translation_Type', y='Correctness_Score', hue='Generator', 
            palette=colors, ax=axes[0])
axes[0].set_title('Avg Correctness: Literal vs. Natural', fontsize=14)
axes[0].set_ylim(0, 110)
for container in axes[0].containers:
    axes[0].bar_label(container, fmt='%.1f', padding=3)

# Security comparison
sns.barplot(data=trans_stats, x='Translation_Type', y='Security_Score', hue='Generator', 
            palette=colors, ax=axes[1])
axes[1].set_title('Avg Security: Literal vs. Natural', fontsize=14)
axes[1].set_ylim(0, 110)
for container in axes[1].containers:
    axes[1].bar_label(container, fmt='%.1f', padding=3)

plt.tight_layout()
plt.show()


# In[22]:


# Creating a 3-panel plot for correctness scores
colors = {
    'Literal': '#FF0000', # Red
    'Natural': '#0000FF'  # A different Blue
}

g_corr = sns.catplot(
    data=combined_df, 
    x='Language', 
    y='Correctness_Score', 
    hue='Translation_Type', 
    col='Generator', 
    kind='bar', 
    palette=colors,
    height=5, 
    aspect=1.2,
    errorbar=None
)

for ax in g_corr.axes.flat:
    for container in ax.containers:
        ax.bar_label(container, fmt='%.1f', padding=3, fontsize=8)
    ax.set_xticklabels(ax.get_xticklabels(), rotation=45)

plt.subplots_adjust(top=0.85)
g_corr.fig.suptitle('Correctness Scores by Language, Translation Type, and Generator', fontsize=16)
plt.show()


# In[23]:


# Creating a 3-panel plot for security scores
colors = {
    'Literal': '#FF0000', # Red
    'Natural': '#0000FF'  # A different Blue
}

g_corr = sns.catplot(
    data=combined_df, 
    x='Language', 
    y='Security_Score', 
    hue='Translation_Type', 
    col='Generator', 
    kind='bar', 
    palette=colors,
    height=5, 
    aspect=1.2,
    errorbar=None
)

for ax in g_corr.axes.flat:
    for container in ax.containers:
        ax.bar_label(container, fmt='%.1f', padding=3, fontsize=8)
    ax.set_xticklabels(ax.get_xticklabels(), rotation=45)

plt.subplots_adjust(top=0.85)
g_corr.fig.suptitle('Security Scores by Language, Translation Type, and Generator', fontsize=16)
plt.show()


# In[24]:


# Creating a table for correctness scores
correctness_table = combined_df.pivot_table(
    index=['Language', 'Translation_Type'], 
    columns='Generator', 
    values='Correctness_Score', 
    aggfunc='mean'
).round(1)

# Creating a table for security scores
security_table = combined_df.pivot_table(
    index=['Language', 'Translation_Type'], 
    columns='Generator', 
    values='Security_Score', 
    aggfunc='mean'
).round(1)

# Displaying the tables
print("Average Correctness Score: Language & Translation Type")
display(security_table)

print("\nAverage Security Score: Language & Translation Type")
display(correctness_table)


# In[25]:


# Creating a scatter plot for the scores.
all_dfs = []
for file in file_list:
    if os.path.exists(file):
        df = pd.read_csv(file)
        parts = file.replace('.csv', '').split('_Code_Evaluation_By_')
        df['Generator'] = parts[0]
        all_dfs.append(df)

combined_df = pd.concat(all_dfs, ignore_index=True)

colors = {
    'ChatGPT': '#2ecc71', # Green
    'Claude': '#e67e22',  # Orange
    'Gemini': '#3498db'   # Blue
}

# Creating the Scatter Plot
plt.figure(figsize=(12, 8))
sns.set_theme(style="whitegrid")

scatter_plot = sns.scatterplot(
    data=combined_df, 
    x='Correctness_Score', 
    y='Security_Score', 
    hue='Generator', 
    palette=colors,
    alpha=0.6,   # Adding transparency to see overlapping points better
    edgecolor='w',
    s=100        # Marker size
)

# Formatting the chart
plt.title('Correctness vs Security Scores by Model', fontsize=16)
plt.xlabel('Correctness Score', fontsize=12)
plt.ylabel('Security Score', fontsize=12)
plt.legend(title='Generator Model', bbox_to_anchor=(1.05, 1), loc='upper left')

plt.tight_layout()
plt.show()

