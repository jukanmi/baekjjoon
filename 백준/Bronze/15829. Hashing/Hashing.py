import sys
input=sys.stdin.readline
n=int(input())
t=input().rstrip('\n')
ans=0
for x in range(n):
    ans+=(ord(t[x])-96)*pow(31,x)%1234567891
print(ans%1234567891)
