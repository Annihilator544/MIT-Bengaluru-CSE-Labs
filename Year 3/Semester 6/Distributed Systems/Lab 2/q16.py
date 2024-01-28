import pandas as pd

data ={
    'name':['Annie','Diya', 'Charles', 'James', 'Emily'],
    'Quiz_1/10':[9, 8, 7, 6, 5],
    'In-Sem_1/15':[14, 13, 12, 11, 10],
    'Quiz_2/10':[8, 7, 6, 5, 4],
    'In-Sem_2/15':[13, 12, 11, 10, 9],
}


df = pd.DataFrame(data)

#add total marks table
df['Total'] = df['Quiz_1/10'] + df['In-Sem_1/15'] + df['Quiz_2/10'] + df['In-Sem_2/15']

#add Mean marks row
print(df)
print(df[['Quiz_1/10','In-Sem_1/15','Quiz_2/10','In-Sem_2/15']].mean())