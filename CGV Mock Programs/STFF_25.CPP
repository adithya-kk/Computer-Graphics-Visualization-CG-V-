#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
int a[]={150,100,100,200,200,200,150,100};
int b[]={100,125,150,225,200,125,100,125};
drawpoly(4,a);
delay(1000);
setfillstyle(SOLID_FILL,GREEN);
floodfill(150,111,WHITE);
delay(1000);
drawpoly(4,b);
setfillstyle(SOLID_FILL,GREEN);
floodfill(111,126,WHITE);
delay(1000);
setfillstyle(SOLID_FILL,GREEN);
floodfill(150,222,WHITE);
delay(1000);
setfillstyle(SOLID_FILL,GREEN);
floodfill(198,126,WHITE);
delay(1000);
getch();
closegraph();
}