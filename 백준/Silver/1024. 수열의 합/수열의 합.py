N,L=map(int,input().split())
for i in range(L,101):
    if i%2==0:
        if (N/i)%1==0.5:
            if N/i+0.5-i/2>=0:
                for x in range(-1*(i//2),i//2):
                    print(int(N/i+0.5+x),end=" ")
            else:
                print(-1)
            raise SystemExit
    else:
        if N%i==0:
            if  N/i-(i-1)/2>=0:
                for x in range(-1*(i//2),i//2+1):
                    print(int(N/i+x),end=" ")
            else:
                print(-1)
            raise SystemExit
print(-1)
