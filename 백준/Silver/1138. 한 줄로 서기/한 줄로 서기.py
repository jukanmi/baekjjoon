import sys
input=sys.stdin.readline
N=int(input())
tall=list(map(int,input().split()))
stand=[]
for x in range(N,0,-1):
    stand.insert(tall[x-1],x)
for x in stand:
    print(x,end=" ")
