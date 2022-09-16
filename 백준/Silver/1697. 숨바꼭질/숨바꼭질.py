import sys
input=sys.stdin.readline
vis=[0 for _ in range(100001)]
def pop(N):
    temp=N[0]
    N=N[1:]
    return temp
tri=0
N,K=map(int,input().split())
base=[N,-1]
while True:
    tmp=base[0]
    base=base[1:]
    if tmp==K:
        print(tri)
        break
    if tmp==-1:
        base.append(-1)
        tri+=1
        continue
    if tmp>=1 and vis[tmp-1]==0:
        base.append(tmp-1)
        vis[tmp-1]=1
    if tmp+1<=100000 and vis[tmp+1]==0:
        base.append(tmp+1)
        vis[tmp+1]=1
    if tmp*2<=100000 and vis[tmp*2]==0:
        base.append(tmp*2)
        vis[tmp*2]=1
