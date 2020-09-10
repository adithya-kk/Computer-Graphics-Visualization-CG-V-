#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
int gd=DETECT,gm,x,y,x1,y1,r;
float dp;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();
printf("Enter The Radius Of Circle");
scanf("%d",&r);
x=0;
y=r;
dp=3-2*r;

do
{
putpixel(x+200,y+200,5);
putpixel(x+200,-y+200,6);
putpixel(-x+200,y+200,5);
putpixel(-x+200,-y+200,7);
putpixel(y+200,x+200,4);
putpixel(y+200,-x+200,5);
putpixel(-y+200,x+200,5);
putpixel(-y+200,-x+200,4);

if(dp<0)
{
 dp=dp+(4*x)+6;
}
else

{
 dp=dp+4*(x-y)+10;
 y--;
}

x++;

}while(x<=y);

getch();

}