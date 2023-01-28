from fractions import Fraction
while (1):
    try:
        s=input()
        a,b=s.split(".")
        c,d=b.split("(")
        d=d[:-1]
        b=a+c
        ans=Fraction(int(b+d)-int(b),pow(10,len(c+d))-pow(10,len(c)))
        print(s,"=",ans.numerator,"/",ans.denominator)
    except:
        break
