N=int(input())
y=list(map(int,input().split()))
y.sort()
print(y[0]*y[N-1])
