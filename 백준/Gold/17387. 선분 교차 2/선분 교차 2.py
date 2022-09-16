import sys
input=sys.stdin.readline
def ccw(x1,y1,x2,y2,x3,y3):
    return x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3
x1,y1,x2,y2=map(int,input().split())
x3,y3,x4,y4=map(int,input().split())
if (y2-y1)*(x3-x4)==(y3-y4)*(x2-x1):#두 선분 기울기 같음
    if (y2-y1)*(x3-x1)!=(y3-y1)*(x2-x1):#세점이 한 직선위에 없음
        print(0)
        #print("평행 교점x")
    else:
        #print("4점 한직선")
        if x1==x2:
            if y2<y1:
                y2,y1=y1,y2
            if y4<y3:
                y4,y3=y3,y4
            if (y1<=y3 and y3<=y2)or(y1<=y4 and y4<=y2)or(y3<=y1 and y1<=y4)or (y3<=y2 and y2<=y4):
                print(1)
            else:
                print(0)
            raise SystemExit
        if x2<x1:
            x2,x1=x1,x2
        if x4<x3:
            x4,x3=x3,x4
        if (x1<=x3 and x3<=x2)or(x1<=x4 and x4<=x2)or(x3<=x1 and x1<=x4)or (x3<=x2 and x2<=x4):
            print(1)
        else:
            print(0)
    raise SystemExit
if ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4)<=0 and ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)<=0:
    print(1)
else:
    print(0)
