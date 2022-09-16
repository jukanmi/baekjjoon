import sys
input=sys.stdin.readline
N=int(input())
nosee=[1 for _ in range(N)]
see=[0 for _ in range(N)]
build=list(map(int,input().split()))
for i in range(N):
    for j in range(i-1,-1,-1):
        for z in range(j-1,-1,-1):
            if (build[i]-build[z])*(i-j)>=(build[i]-build[j])*(i-z):
                nosee[z]=0
    for j in range(i+1,N):
        for z in range(j+1,N):
            if (build[z]-build[i])*(j-i)<=(build[j]-build[i])*(z-i):
                nosee[z]=0
    for x in range(N):
        if nosee[x]==1:
            see[x]+=1
        else:
            nosee[x]=1
print(max(see)-1)
