N=int(input())
dic={}
for _ in range(N):
    a,b=input().split(".")
    
    if b in dic:
        dic[b]+=1
    else:
        dic[b]=1
L=list(sorted(dic.items()))
for x in L:
    print(x[0],x[1])

