#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void moonMotion(int r,int midx,int midy,int x[60],int y[60])
{
 int i,j=0;
 for(i=360;i>0;i=i-6)
 {
  x[j]=midx-(r*cos((i*3.14)/180));
  y[j++]=midy-(r*sin((i*3.14)/180));
 }
 return;
}

int main()
{
 int gd=DETECT,gm;
 int midx,midy,earth,moon,orbit;
 int i=0,x[60],y[60];
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 earth=50,orbit=100,moon=25;
 midx=getmaxx()/2;
 midy=getmaxy()/2;

 moonMotion(orbit,midx,midy,x,y);

 while(!kbhit())
 {
  outtextxy(midx-20,midy-20,"EARTH");
  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  pieslice(midx,midy,0,360,earth);

  setcolor(WHITE);
  setlinestyle(DASHED_LINE,1,1);
  circle(midx,midy,orbit);

  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  setlinestyle(SOLID_LINE,1,1);
  pieslice(x[i],y[i],0,360,moon);
  delay(200);
  cleardevice();
  i=(i+1)%60;
 }
 closegraph();
 getch();
}