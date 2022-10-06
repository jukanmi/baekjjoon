N=int(input())
gra={}
for _ in range(N):
    x,y=map(int,input().split())
    if x in gra:
        gra[x].append(y)
    else:
        gra[x]=[y]
for x in gra.keys():
    gra[x].sort()
sor=sorted(gra.items(),key=lambda x:x)
for x in sor:
    for y in x[1]:
        print(x[0],y)
