L=int(input())
A=list(map(int,input().split(" ")))
n=int(input())
A.sort()
for x in range(L):
    if int(A[x])>n:
        break
    elif int(A[x])==n:
        print("0")
        raise SystemExit
if x==0:
    left=int(A[0])-n
    right=n
else:
    left=int(A[x])-n
    right=n-int(A[x-1])
print((left*right)-1)