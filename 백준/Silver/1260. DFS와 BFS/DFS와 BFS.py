
def dfs(start,check=[]):
    print(start,end=' ')
    check.append(start)
    for i in mat[start]:
        if i not in check:
            dfs(i)
            check.append(i)
    
    
    
def bfs(start):
    print()
    check=[start]
    queue=[start]
    tum,popi=0,1
    while len(queue)>0:
        popi=queue[0]
        queue=queue[1:]
        print(popi,end=" ")
        for i in mat[popi]:
            if i not in check:
                queue.append(i)
                check.append(i)
        

N,M,V=map(int,input().split())
mat=[[] for _ in range(N+1)]
for _ in range(M):
    a,b=map(int,input().split())
    mat[a].append(b)
    mat[b].append(a)
for i in range(len(mat)):
    mat[i].sort()
dfs(V)
bfs(V)
