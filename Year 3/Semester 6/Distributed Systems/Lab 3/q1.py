import numpy as np

x = int(input("Enter the Num: "))

factors = np.array([i for i in range(1, x+1) if x%i == 0])

print(factors)