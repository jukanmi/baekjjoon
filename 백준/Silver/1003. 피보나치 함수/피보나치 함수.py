z=int(input())
while z!=0:
    z-=1
    n=int(input())
    a=0
    a00=1
    a01=0
    a10=0
    a11=1
    if n==0:
        print("1",'0')
        a=1
    elif n==1:
        print('0','1')
        a=1
    while (n-1)!=0 and a==0:
        n-=1
        a00=a00+a01
        a10=a10+a11
        a00,a01=a01,a00
        a10,a11=a11,a10
    if a==0:
        print(a01,a11)