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
    heap=[]#쓸 힙
    heappush(heap,[0,start])#시작 넣기
    while len(heap)!=0:
        totalpay,ennd=heappop(heap)
        #print(INF,ennd)
        if INF[ennd]<totalpay:
            continue
        INF[ennd]=totalpay
        #print(ennd)
        for e,p in s[ennd]:
            if p+INF[ennd]<INF[e]:
                INF[e]=p+INF[ennd]
                heappush(heap,[INF[ennd]+p,e])
        #print(heap)
    return INF[end]
print(dakisk(start,end))
"""
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

4

6
2
1 1 4
1 1 2
1 1

2

2
2
1 1 1
1 2 4
1 2

4

2
3
1 1 10
1 2 4
2 1 2
1 1

6

"""
