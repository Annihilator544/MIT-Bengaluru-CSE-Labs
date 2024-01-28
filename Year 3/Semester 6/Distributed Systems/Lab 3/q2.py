#  find the sum of columns and rows using axis
import pandas as pd

df =pd.DataFrame({'A':[1,2,3,4,5],
                    'B':[5,6,7,8,9],
                    'C':[10,11,12,13,14],
                    'D':[15,16,17,18,19],
                    'E':[20,21,22,23,24]})
row_sum = df.sum(axis=1)
col_sum = df.sum(axis=0)
print("Row Sum: \n", row_sum)
print("Column Sum: \n", col_sum)
