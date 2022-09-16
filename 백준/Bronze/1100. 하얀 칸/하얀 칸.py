a=[]
kni=0
for _ in range(8):
    a.append(input())
for x in range(8):
    for i in range(x%2,8,2):
        if a[x][i]=="F":
            kni+=1
print(kni)
