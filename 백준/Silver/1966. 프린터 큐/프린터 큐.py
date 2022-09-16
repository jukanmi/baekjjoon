import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    tr=0
    n,m=map(int,input().split())
    queue=list(map(int,input().split()))
    for x in range(len(queue)):
        queue[x]+=x*10
    m=queue[m]
    max=0
    
    while len(queue)>0:
        c,max=0,0
        for r in range(len(queue)):
            if max<queue[r]%10:
                max=queue[r]%10
                c=r
        x=queue[c]
        queue=queue[c+1:]+queue[:c]
        tr+=1
        if x==m:
            break
    print(tr)
