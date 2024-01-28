tuuple=(12,7,38,56,78)
i=0
y=[]
for x in tuuple:
	if(int(x)%2==0):
		y.append(x)
x=tuple(y)
print(x)
