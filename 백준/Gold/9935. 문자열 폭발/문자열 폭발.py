import sys
input=sys.stdin.readline
N=input()
W=input()
N=N[:-1]
W=W[:-1]
w=list(W)
before=-1

stack=[]
for cha in N:
    stack.append(cha)
    if cha==W[-1] and w==stack[-len(W):]:
        del stack[-len(W):]
N="".join(stack)
if len(N)==0:
    print("FRULA")
else:
    print(N)
            
#mirkovC4nizCC44
#C4
