#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
typedef long long ll;
int p[4][2];
int ccw(int *p1, int *p2, int *p3){
    ll ans=(ll)p1[0]*p2[1]+(ll)p2[0]*p3[1]+(ll)p3[0]*p1[1]-(ll)p2[0]*p1[1]-(ll)p3[0]*p2[1]-(ll)p1[0]*p3[1];
    if (ans<0) return -1;
    if (ans>0) return 1;
    return 0;
}
int main(){
    scanf("%d%d%d%d%d%d%d%d",&p[0][0],&p[0][1],&p[1][0],&p[1][1],&p[2][0],&p[2][1],&p[3][0],&p[3][1]);
    if (max(p[0][0],p[1][0])<min(p[2][0],p[3][0])||min(p[0][0],p[1][0])>max(p[2][0],p[3][0])||max(p[0][1],p[1][1])<min(p[2][1],p[3][1])||min(p[0][1],p[1][1])>max(p[2][1],p[3][1])){puts("0"); return 0;}
    int ccw1=ccw(p[0],p[1],p[2]),ccw2=ccw(p[0],p[1],p[3]),ccw3=ccw(p[2],p[3],p[0]),ccw4=ccw(p[2],p[3],p[1]);
    if (ccw1*ccw2<=0 && ccw3*ccw4<=0){
        puts("1");
        if (ccw1||ccw2||ccw3||ccw4){
            if (p[1][0]==p[0][0]){
                double a2=(p[3][1]-p[2][1])/(double)(p[3][0]-p[2][0]);
                double b2=p[2][1]-p[2][0]*a2;
                printf("%d %.16lf\n",p[1][0],a2*p[1][0]+b2);
            }
            else if (p[3][0]==p[2][0]){
                double a1=(p[1][1]-p[0][1])/(double)(p[1][0]-p[0][0]);
                double b1=p[0][1]-p[0][0]*a1;
                printf("%d %.16lf\n",p[2][0],a1*p[2][0]+b1);
            }
            else{
                double a1=(p[1][1]-p[0][1])/(double)(p[1][0]-p[0][0]),a2=(p[3][1]-p[2][1])/(double)(p[3][0]-p[2][0]);
                double b1=p[0][1]-p[0][0]*a1,b2=p[2][1]-p[2][0]*a2;
                printf("%.16lf %.16lf\n",-(b1-b2)/(a1-a2),a1*(-(b1-b2)/(a1-a2))+b1);
            }
        }
        else if ((p[0][0]==p[2][0]&&p[0][1]==p[2][1]&&(p[1][0]-p[0][0])*(p[3][0]-p[2][0])<=0)||(p[0][0]==p[3][0]&&p[0][1]==p[3][1]&&(p[1][0]-p[0][0])*(p[2][0]-p[3][0])<=0))
            printf("%d %d\n",p[0][0],p[0][1]);
        else if ((p[1][0]==p[2][0]&&p[1][1]==p[2][1]&&(p[0][0]-p[1][0])*(p[3][0]-p[2][0])<=0)||(p[1][0]==p[3][0]&&p[1][1]==p[3][1]&&(p[0][0]-p[1][0])*(p[2][0]-p[3][0])<=0))
            printf("%d %d\n",p[1][0],p[1][1]);
    }
    else
        puts("0");
}
