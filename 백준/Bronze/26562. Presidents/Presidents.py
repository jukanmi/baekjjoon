import sys
input = sys.stdin.readline
pay={"Franklin":100, "Grant":50, "Jackson":20, "Hamilton":10, "Lincoln":5, "Washington":1}
n=int(input())
for _ in range(n):
    ans=0
    name=input().split()
    for x in name:
        ans+=pay[x]
    print('$',ans,sep="")
