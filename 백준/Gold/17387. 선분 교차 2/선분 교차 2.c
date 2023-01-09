#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
typedef long long ll;
ll p[4][2];
int ccw(ll *p1, ll *p2, ll *p3){
    ll ans=p1[0]*p2[1]+p2[0]*p3[1]+p3[0]*p1[1]-p2[0]*p1[1]-p3[0]*p2[1]-p1[0]*p3[1];
    if (ans<0) return -1;
    if (ans>0) return 1;
    return 0;
}
int main(){
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&p[0][0],&p[0][1],&p[1][0],&p[1][1],&p[2][0],&p[2][1],&p[3][0],&p[3][1]);
    if (max(p[0][0],p[1][0])<min(p[2][0],p[3][0])){puts("0"); return 0;}
    if (min(p[0][0],p[1][0])>max(p[2][0],p[3][0])){puts("0"); return 0;}
    if (max(p[0][1],p[1][1])<min(p[2][1],p[3][1])){puts("0"); return 0;}
    if (min(p[0][1],p[1][1])>max(p[2][1],p[3][1])){puts("0"); return 0;}
    if (ccw(p[0],p[1],p[2])*ccw(p[0],p[1],p[3])<=0 && ccw(p[2],p[3],p[0])*ccw(p[2],p[3],p[1])<=0)
        puts("1");
    else
        puts("0");
}
