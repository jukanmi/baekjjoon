import sys
input = sys.stdin.readline
from math import gcd
N,S=map(int,input().split())
arr=list(map(int,input().split()))
ans=S-arr[0]
for x in arr:
    ans=gcd(ans,abs(S-x))
print(ans)
