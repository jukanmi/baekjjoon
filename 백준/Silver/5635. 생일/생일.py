n=int(input())
stage=[]
for _ in range(n):
    arr=list(input().split())
    for x in range(1,4):
        arr[x]=int(arr[x])
    stage.append(arr[::-1])
stage.sort()
print(stage[len(stage)-1][3])
print(stage[0][3])
