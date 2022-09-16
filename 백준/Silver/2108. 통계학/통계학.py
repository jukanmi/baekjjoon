import sys
input=sys.stdin.readline
N=int(input())
num=[]
for _ in range(N):
    num.append(int(input()))
num.sort()
print(round(sum(num)/len(num)))
print(num[len(num)//2])
dic={}
for x in num:
    if x in dic:
        dic[x]+=1
    else:
        dic[x]=1
ans=[]
ma=-4001
for x in dic.items():
    if ma<x[1]:
        ans=[]
        ma=x[1]
        ans.append(x[0])
    elif ma==x[1]:
        ans.append(x[0])
if len(ans)==1:
    print(ans[0])
else:
    print(ans[1])
print(max(num)-min(num))
