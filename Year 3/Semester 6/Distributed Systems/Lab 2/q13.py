import pandas as pd

data ={
    'name':['Jerry','Riah','Paul'],
    'Height':[180, 175, 190],
    'Qualification':['PhD','MS','MS'],
}

df = pd.DataFrame(data)

lista = ['Seoul','Yongin','Seoul']

#use address as column nameand equate it to list 

df.insert(3,'Address',lista)

print(df)