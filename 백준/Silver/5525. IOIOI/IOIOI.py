import sys
input=sys.stdin.readline

N=int(input())
M=int(input())
A=0#OI가 몇번 반복됐는지
B=0#실질적 더함
C=0#발동 조건
S=input()
x=0
while x <len(S):
    if C!=0:
        #print(S[x:x+2],x)
        if S[x:x+2]=="OI":
            x+=2
            A+=1
        else:
            C=0
            A=0
    else:
        if S[x]=="I":
            C=1
        x+=1
    if A==N:
        B+=1
        A-=1
    #print(A,B,C)
    
print(B)
