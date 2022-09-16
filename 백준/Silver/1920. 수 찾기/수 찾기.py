import sys
N=int(sys.stdin.readline())
A=sys.stdin.readline().split()
A.sort()
M=int(sys.stdin.readline())
a=sys.stdin.readline().split()
for i in range(M):
    left=0
    right=len(A)-1
    while left <=right:
        mid=(left+right)//2
        if a[i]==A[mid]:
            print(1)
            break
        elif a[i] <A[mid]:
            right=mid-1
        else:
            left=mid+1
    if a[i]!=A[mid]:
        print(0)
    