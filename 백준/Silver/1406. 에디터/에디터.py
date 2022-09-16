import sys
input=sys.stdin.readline
from collections import deque
N=deque(input())
N.pop()
M=int(input())
curleft=N
curright=deque()
for _ in range(M):
    X=list(input().split())
    if X[0]=="P":
        curleft.append(X[1])
    elif X[0]=="L" and len(curleft)!=0:
        curright.appendleft(curleft.pop())
    elif X[0]=="D" and len(curright)!=0:
        curleft.append(curright.popleft())
    elif X[0]=="B" and len(curleft)!=0:
       curleft.pop() 
for x in curleft:
    print(x,end="")
for x in curright:
    print(x,end="")
