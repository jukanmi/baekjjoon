#include <stdio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int day=y;
    while (x>1){
        day+=month[--x];
    }
    switch (day%7)
    {
    case 1:printf("MON");
        break;
    case 2:printf("TUE");
        break;
    case 3:printf("WED");
        break;
    case 4:printf("THU");
        break;
    case 5:printf("FRI");
        break;
    case 6:printf("SAT");
        break;
    case 0:printf("SUN");
        break;
    default:
        break;
    }
}