import sys
input = sys.stdin.readline
import re
T=int(input())
nor=re.compile('(100+1+|01)+')
for _ in range(T):
    if nor.fullmatch(input().rstrip()):
        print("YES")
    else:
        print("NO")
