#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
int gdriver=DETECT,gmode,i=0,j=0;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
for(i;i<420;++i)
{
line(0,245,650,245);
line(80+i,230,100+i,200);
line(130+i,230,120+i,200);
line(80+i,200,150+i,200);
line(150+i,200,150+i,180);
ellipse(150+i,180,0,90,5,8);
ellipse(150+i,180,270,0,5,8);
line(100+i,200,100+i,190);
setcolor(YELLOW);
circle(100+i,190,3);
circle(65+i,230,15);
line(80+i,230,130+i,230);
circle(145+i,230,15);
pieslice(65+i,230,359-j,360-j,15);
pieslice(65+i,230,179-j,180-j,15);
pieslice(65+i,230,89-j,90-j,15);
pieslice(65+i,230,269-j,270-j,15);
pieslice(145+i,230,359-j,360-j,15);
pieslice(145+i,230,179-j,180-j,15);
pieslice(145+i,230,89-j,90-j,15);
pieslice(145+i,230,269-j,270-j,15);
if(j==179)
j=0;
++j;
delay(20);
cleardevice();
}
closegraph();
}
