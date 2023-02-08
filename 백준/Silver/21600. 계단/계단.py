import sys
input = sys.stdin.readline
n = int(input())
stairs = []
histogram = list(map(int,input().split()))
l=len(histogram)
for i in range(l):
    howlong = 1
    current = i
    while howlong < histogram[current]:
        howlong += 1
        if current == l - 1:
            break
        current += 1
    stairs.append(howlong)
print(max(stairs))
