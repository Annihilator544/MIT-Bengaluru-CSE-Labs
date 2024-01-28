x=int(input("Enter Num 1:"))
y=int(input("Enter Num 2:"))
z=int(input("Enter Num 3:"))
if(x>y and x>z):
	print(x, " is greatest")
elif(y>x and y>z):
	print(y, " is greatest")
elif(z>y and z>x):
	print(z, " is greatest")
else:
	print("two or more numbers are same")
