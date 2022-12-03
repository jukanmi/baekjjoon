a,b=map(int,input().split())
def add(num):
    if num<=0:
        return 0
    power=len(str(num))-1
    ans=0
    cur=0
    while power>=0:
        a=num//pow(10,power)
        num-=a*pow(10,power)
        if power!=0:
            ans+=45*a*power*pow(10,power-1)
        ans+=(a-1)*a//2*pow(10,power)+cur*a*pow(10,power)+a
        cur+=a
        power-=1
    return ans
print(add(b)-add(a-1))
