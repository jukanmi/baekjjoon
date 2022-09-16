import sys
input=sys.stdin.readline
n=int(input())
li=list(map(int,input().split()))
note=[li[0]]
for x in range(1,len(li)):
    if note[x-1]<0:
        note.append(li[x])
    else:
        note.append(li[x]+note[x-1])
print(max(note))
