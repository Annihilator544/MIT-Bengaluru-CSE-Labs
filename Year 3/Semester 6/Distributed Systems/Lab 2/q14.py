import pandas as pd

data ={
    'name':['Jerry','Riah','Paul'],
    'Height':[180, 175, 190],
    'Qualification':['PhD','MS','MS'],
}

df = pd.DataFrame(data)

df.insert(3,'Address',['Seoul','Yongin','Seoul'])

print(df)