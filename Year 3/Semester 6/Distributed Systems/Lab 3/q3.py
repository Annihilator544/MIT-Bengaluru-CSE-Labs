import numpy as np

arr1 = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], dtype=float)

# create array from tuple
tuple = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
arr2 = np.array(tuple, dtype=float)

# create a 3x4 array with all values 0
arr3 = np.zeros((3, 4))

# create a sequence of integers from 0 to 20 with steps of 5
arr4 = np.arange(0, 20, 5)

#  reshape 3x4 array to 2x2x3 array
arr5 = arr3.reshape(2, 2, 3)

# find maximum and minimum values of array, row and column
arr6 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
max = arr6.max()
min = arr6.min()
max_row = arr6.max(axis=0)
min_row = arr6.min(axis=0)
max_col = arr6.max(axis=1)
min_col = arr6.min(axis=1)
