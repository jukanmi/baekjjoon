import sys
input=sys.stdin.readline
N=int(input())
pra=[[] for _ in range(N)]
for x in range(N):
    pra[x]=list(map(int,input().split()))
dp=pra[N-1]
for x in range(N-1,0,-1):
    for y in range(x):
        dp[y]=max(dp[y],dp[y+1])+pra[x-1][y]
print(dp[0])
