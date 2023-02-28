import sys
input=sys.stdin.readline
point=[10,8,6,5,4,3,2,1,0]
s=[]
for _ in range(8):
    s.append(input().split())
s.sort()
score={"R":0,"B":0}
for x in range(8):
    score[s[x][1]]+=point[x]
if score["R"]>score["B"]:
    print("Red")
else:
    print("Blue")
