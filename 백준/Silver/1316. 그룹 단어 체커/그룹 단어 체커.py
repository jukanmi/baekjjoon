n=int(input())
word=0
z=0
for i in range(n):
    a=input()
    b={}
    re=""
    for x in a:
        if x in b.keys() and re!=x:
            z=1
            break
        elif not(x in b):
            b[x]=1
        re=x
        z=0
    if z==1:
        continue
    word+=1
print(word)
