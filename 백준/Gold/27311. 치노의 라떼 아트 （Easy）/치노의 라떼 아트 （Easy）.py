import sys
input = sys.stdin.readline
def check(arr):
    A=[]
    flag=False
    for x in arr:
        s=x.strip(".")
        if s.find(".")!=-1:
            return False
        if s!="":
            if flag:
                return False
            start=x.find("#")
            A.append([start,len(s)])
        else:
            if len(A)!=0:
                flag=True
            
    #print(A)
    if len(A)<=1:
        return False
    if max(A[0][1],A[-1][1])!=len(A):#정사각형이 아닐때
        return False
    if A[0][0]>A[-1][0] or A[0][1]<A[-1][1]:#항상 빈칸이 아래있도록
        A=A[::-1]
    #print(A)
    start=A[0][0]
    size=A[0][1]
    blank=A[0][1]-A[-1][1]
    if blank==0:
        return False
    for x in range(A[0][1]-blank):
        if A[x][0]!=start or A[x][1]!=size:
            return False
    if A[-1][0]==start:#우하가 빔
        for x in range(A[0][1]-blank,size):
            if A[x][0]!=start or A[x][1]!=size-blank:
                return False
    else:#좌하가 빔
        for x in range(A[0][1]-blank,size):
            if start+blank!=A[x][0] or A[x][1]!=size-blank:
                return False
    return True
        
        
    
        
            
T=int(input())
for _ in range(T):
    R,C=map(int,input().split())
    arr=[]
    for x in range(R):
        arr.append(input().rstrip("\n"))
    if check(arr):
        print(1)
    else:
        print(0)
    
'''
1
6 9
...####..
.........
...####..
...####..
....###..
.........
'''
