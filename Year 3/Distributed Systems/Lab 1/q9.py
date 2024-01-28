list=[11,-21,0,45,66,-93]
count=0
count2=0
for x in list:
  if(x<0):
  	count+=1
  else:
  	count2+=2
print("number of positive numbers are",count2)
print("number of negative numbers are",count)
