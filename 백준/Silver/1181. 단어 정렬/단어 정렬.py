n=int(input())
a=[]
b={}
for _ in range(n):
    a.append(input())
a.sort()
for x in a:
    if len(x) in b:
        if x not in b[len(x)]:
            b[len(x)].append(x)
    else:
        b[len(x)]=[x]

a=sorted(b.items(),key=lambda x:x)
for x in a:
    for y in x[1][:]:
        print(y)
