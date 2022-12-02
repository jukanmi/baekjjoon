import random
from math import gcd
import sys
input = sys.stdin.readline
def miller(n, a):#n이 소수조건 만족하면 True 단 True여도 소수가 아닐수 있음
    if a==n:
        return True
    if a%n==0:
        return False
    k=n-1
    while True:
        tmp=pow(a,k,n)#(a**k)(mod n)
        if tmp==n-1:
            return True
        if k%2==1:
            if tmp==1 or tmp==n-1:#나머지가 1 or -1
                return True
            else:
                return False
        k//=2

def primecheck(n):#소수면 True출력
    primeNumber={2,3,5,7,11,13,17,19,23,29,31,37}#long long 범위일때 판정가능한 범주  
    for a in primeNumber:
        if miller(n,a)==False:
            return False
    return True

def mod(x,c,num):
    return (x*x+c)%num

def pollard_rho(number):
    if primecheck(number):
        return [number]
    if number==4:
        return [2,2]
    while 1:
        c=random.randint(1,10)
        x=random.randint(1,10)
        y=x
        d=1
        while d==1:#1도 소인수므로 탈출방지
            x=mod(x,c,number)
            y=mod(mod(y,c,number),c,number)
            d=gcd(abs(x-y),number)#abs(x-y)=number보다 작은 난수로 생성된 수
        if d==number:#마찬가지
            continue
        return pollard_rho(number//d)+pollard_rho(d)
N=int(input())
ans=0
for _ in range(N):
    if primecheck(2*int(input())+1):
        ans+=1
print(ans)
