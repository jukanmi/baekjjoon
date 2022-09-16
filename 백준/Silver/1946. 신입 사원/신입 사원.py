import sys
input=sys.stdin.readline
from collections import deque
t=int(input())
for _ in range(t):
    n=int(input())
    stock=[]
    for x in range(n):
        stock.append(list(map(int,input().split())))
    stock.sort(key=lambda a:a[0])
    st=100001
    ans=0
    for x in stock:
        if st<=x[1]:
            ans+=1
        else:
            st=x[1]
    print(n-ans)
