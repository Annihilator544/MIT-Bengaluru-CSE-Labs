'''
Exercise 5: Try to apply finding max value using map reduce concept for the output of Heart 
Disease dataset, covid_19_data dataset, example dataset and German Credit dataset.
'''

from collections import defaultdict
import pandas as pd
import numpy as np
import os

def mapper(text):
    word_counts = defaultdict(int)
    words = str(text).split()
    for word in words:
        word_counts[word] += 1
    return word_counts

def reducer(word_counts_list):
    final_counts = defaultdict(int)
    for word_counts in word_counts_list:
        for word, count in word_counts.items():
            final_counts[word] += count
    return final_counts

def printer(input_data):
    mapped_data = [mapper(line) for line in input_data]
    # for line in mapped_data:
    #     print(line)

    reduced_result = reducer(mapped_data)
    # for word, count in reduced_result.items():
    #     print(f"{word}: {count}")
        
    # most common word
    print(max(reduced_result, key=reduced_result.get), reduced_result[max(reduced_result, key=reduced_result.get)])
    
def maxValue(input_data) :
    mapped_data = [mapper(line) for line in input_data]
    reduced_result = reducer(mapped_data)
    # find the maximum value in input_data
    print(max(input_data))

# Sample input data
# input_data = [
#     "hello world hello",
#     "world python world",
#     "hello python"
# ]
# Get the directory of the current script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Relative path to the CSV file from the script directory
file_path = os.path.join(script_dir, 'covid.csv')
file_path2 = os.path.join(script_dir, 'heart_disease_data.csv')
file_path3 = os.path.join(script_dir, 'HR.txt')
file_path4 = os.path.join(script_dir, 'example.txt')


df1 = pd.read_csv(file_path)
input_data = df1['Confirmed'].tolist()
maxValue(input_data)

df2 = pd.read_csv(file_path2)
input_data = df2['chol'].tolist()
maxValue(input_data)

df3 = pd.read_csv(file_path3, sep='\t')
input_data = df3['Age'].tolist()
maxValue(input_data)

df4 = pd.read_csv(file_path4, sep='\t')
input_data = df4['price'].tolist()
maxValue(input_data)