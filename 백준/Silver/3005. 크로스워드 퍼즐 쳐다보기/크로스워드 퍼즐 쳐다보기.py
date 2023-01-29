N,M=map(int,input().split())
ans="zzzzzzzzzzzzzzzzzzzz"
t=[]
for x in range(N):
    t.append(input())
for x in t:
    for y in x.split('#'):
        if len(y)>=2 and ans>y:
            ans=y
for x in range(M):
    s=""
    for y in range(N):
        if t[y][x]=='#':
            if len(s)>=2 and ans>s:
                ans=s
            s=""
        else:
            s+=t[y][x]
    if len(s)>=2 and ans>s:
        ans=s
        
print(ans)
