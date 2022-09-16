import sys
for y in range(3):
    N=int(sys.stdin.readline())
    a=[0 for _ in range(N)]
    for x in range(N):
        a[x]=int(sys.stdin.readline())
    if sum(a)>0:
        print("+")
    elif sum(a)<0:
        print("-")
    else:
        print("0")
