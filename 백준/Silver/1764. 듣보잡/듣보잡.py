N,M=map(int,input().split())
heard=set()
see=set()
for _ in range(N):
    heard.add(input())
for _ in range(M):
    see.add(input())
a=list(see&heard)
a.sort()
print(len(a))
for x in a:
    print(x)
