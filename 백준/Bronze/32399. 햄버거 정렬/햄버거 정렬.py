a=input()
ans=""
if a=="(1)": 
  ans=0
elif a=="1()" or a=="()1":
  ans=1
elif a==")1(":
  ans=2
elif a=="1)(" or a==")(1":
  ans=1
print(ans)