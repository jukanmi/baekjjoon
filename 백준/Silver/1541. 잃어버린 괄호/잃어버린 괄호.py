x=input()
s,e,pn=0,0,1
ch,ans=0,0
for i in range(len(x)):
    if x[i]=="+":
        if pn==0 or ch==1:
            ans-=int(x[s:e])
        else:
            ans+=int(x[s:e])
        s,e=i+1,i+1
        
    elif x[i]=="-":
        if pn==0 or ch==1:
            ans-=int(x[s:e])
        else:
            ans+=int(x[s:e])
        s,e=i+1,i+1
        ch=1
    else:
        e+=1
if pn==0 or ch==1:
    ans-=int(x[s:e])
else:
    ans+=int(x[s:e])
print(ans)
