def hanoi(n,start,destin,temp):
    if n>1:
        hanoi(n-1,start,temp,destin)
        print(start,destin)
        hanoi(n-1,temp,destin,start)
    else:
        print(start,destin)
    

a=int(input())
d=pow(2,a)-1
print(d)
if a<=20:
    hanoi(a,1,3,2)
