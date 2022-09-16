import sys
input=sys.stdin.readline
sce=[]#[[s,e],[s,e]]
N=int(input())
for _ in range(N):
    s,e=map(int,input().split())
    sce.append([s,e])
sce.sort()
sce=sorted(sce,key=lambda x:x[1])
end=sce[0][1]
cnt=1
for x in range(1,N):
    if end<=sce[x][0]:
        cnt+=1
        end=sce[x][1]
print(cnt)
