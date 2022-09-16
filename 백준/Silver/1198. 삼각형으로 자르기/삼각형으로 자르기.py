import sys
input=sys.stdin.readline
def tri(x1,y1,x2,y2,x3,y3):
    return abs((x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2)
N=int(input())
point=[]
maxs=0
for _ in range(N):
    s=list(map(int,input().split()))
    point.append(s)
for a in range(N-2):
    for b in range(a+1,N-1):
        for c in range(b+1,N):
            x=tri(point[a][0],point[a][1],point[b][0],point[b][1],point[c][0],point[c][1])
            if maxs<x:
                maxs=x
print(maxs)
