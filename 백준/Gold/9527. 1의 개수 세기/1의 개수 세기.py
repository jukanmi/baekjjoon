import sys
import math
input=sys.stdin.readline
def sumz(N):
    shift,shi=1,0
    while shift*2<=N:
        shift<<=1
        shi+=1
    preon,ans=0,0
    while shift!=0:
        if shift & N:
            ans+=fil[shi]+preon*shift
            preon+=1
        shi-=1
        shift>>=1
    return ans
fil=[0 for _ in range(55)]
for i in range(55):
    fil[i]=int(i*pow(2,i-1)+1)
a,b=map(int,input().split())
print(sumz(b)-sumz(a-1))
