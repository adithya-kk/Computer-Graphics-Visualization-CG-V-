#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
int gm=DETECT,gd,maxx,maxy,midx,midy,s1,s2;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C://TURBOC3//BGI");
maxx=getmaxx();
maxy=getmaxx();
midx=maxx/2;
midy=maxy/2;
line(50,50,200,50);
line(200,50,120,180);
line(120,180,50,50);
line(50,150,200,150);
line(50,150,120,30);
line(120,30,200,150);
line(midx,0,midx,maxy);
line(0,midy,maxx,midy);
printf("enter scaling factors");
scanf("%d%d",&s1,&s2);
line(midx+(50*s1),midy-(50*s2),midx+(200*s1),midy-(50*s2));
line(midx+(200*s1),midy-(50*s2),midx+(120*s1),midy-(180*s2));
line(midx+(120*s1),midy-(180*s2),midx+(50*s1),midy-(50*s2));
line(midx+(50*s1),midy-(150*s2),midx+(200*s1),midy-(150*s2));
line(midx+(50*s1),midy-(150*s2),midx+(120*s1),midy-(30*s2));
line(midx+(120*s1),midy-(30*s2),midx+(200*s1),midy-(150*s2));
getch();
closegraph();
}



