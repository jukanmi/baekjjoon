num=0
x=input()
if x==" ":
    print(0)
else:
    for y in range(1,len(x)-1):
        if x[y]==" ":
            num+=1
    print(num+1)
