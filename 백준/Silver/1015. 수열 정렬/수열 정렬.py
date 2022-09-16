n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
for x in range(n):
    for i in range(n):
        if a[x]==b[i]:
            print(i,end=" ")
            b[i]=-1
            break
