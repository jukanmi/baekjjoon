import sys
input=sys.stdin.readline
from heapq import heappush,heappop
N=int(input())
M=int(input())
s=[[] for _ in range(N+1)]#[end,pay]
for _ in range(M):
    start,end,pay=map(int,input().split())
    s[start].append([end,pay])
start,end=map(int,input().split())
def dakisk(start,end):
    INF=[100000*N+1 for _ in range(N+1)]#최대값 초기화
    nod=[[] for _ in range(N+1)]#쓸 노드
    heap=[]#쓸 힙
    heappush(heap,[0,start])#시작 넣기
    nod[start].append(start)
    while len(heap)!=0:#힙끝날때까지 뽑기
        totalpay,ennd=heappop(heap)
        if INF[ennd]<totalpay:
            continue
        INF[ennd]=totalpay
        for e,p in s[ennd]:
            if p+INF[ennd]<INF[e]:
                nod[e]=nod[ennd]+[e]
                INF[e]=p+INF[ennd]
                heappush(heap,[INF[ennd]+p,e])
    print(INF[end])
    print(len(nod[end]))
    for x in nod[end]:
        print(x,end=" ")
dakisk(start,end)
