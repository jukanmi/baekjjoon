x=input()
x=str.upper(x)
al={}
m=0
for i in x:
    if i in al.keys():
        al[i]+=1
    else:
        al[i]=1
for x in al.keys():
    if al[x]>m:
        m=al[x]
        a=x
    elif al[x]==m: a="?"
print(a)
