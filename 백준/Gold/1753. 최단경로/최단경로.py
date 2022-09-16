import sys
input=sys.stdin.readline
from heapq import heappush,heappop
N,M=map(int,input().split())
start=int(input())
s=[[] for _ in range(N+1)]
for _ in range(M):
    sta,end,pay=map(int,input().split())
    s[sta].append([end,pay])
def dakisk(start):
    INF=[10*N+1 for _ in range(N+1)]
    INF[start]=0
    heap=[]
    heappush(heap,[0,start])
    while len(heap)!=0:
        totalpay,ennd=heappop(heap)
        if INF[ennd]<totalpay:
            continue
        INF[ennd]=totalpay
        for e,p in s[ennd]:
            if p+INF[ennd]<INF[e]:
                INF[e]=p+INF[ennd]
                heappush(heap,[INF[ennd]+p,e])
        
    return INF[1:]
for x in dakisk(start):
    if x==10*N+1:
        x="INF"
    print(x)
