N=input()
while N!="0":
    n=0
    for i in range(len(N)//2):
        if N[i]!=N[len(N)-i-1]:
            print("no")
            n=1
            break
    if n==0:
        print("yes")
    N=input()