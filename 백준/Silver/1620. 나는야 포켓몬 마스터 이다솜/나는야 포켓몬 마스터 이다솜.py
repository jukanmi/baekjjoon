N,M=map(int,input().split())
do={}
z=1
for _ in range(N):
    do[z]=input()
    z+=1
sor=sorted(do.items(),key=lambda x:x[1])
for _ in range(M):
    x=input()
    if x.isdigit():
        print(do[int(x)])
    else:
        l,r=1,len(do)
        while l<r:
            m=(l+r)//2
            if sor[m][1]<=x:
                l=m+1
            else:
                r=m
        print(sor[l-1][0])
