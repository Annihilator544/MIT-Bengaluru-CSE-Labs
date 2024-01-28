import pandas as pd

data ={
    'name':['Ram','Diya', 'Chandan', 'James', 'Alice'],
}

data2 = {
    'maths':[90, 80, 70, 60, 50],
    'physics':[80, 70, 60, 50, 40],
    'chemistry':[70, 60, 50, 40, 30],
    'biology':[60, 50, 40, 30, 20],
}

df1 = pd.DataFrame(data)
df2 = pd.DataFrame(data2)

df = pd.concat([df1, df2], axis=1)
#add total marks table
df['Total'] = df['maths'] + df['physics'] + df['chemistry'] + df['biology']

print(df)