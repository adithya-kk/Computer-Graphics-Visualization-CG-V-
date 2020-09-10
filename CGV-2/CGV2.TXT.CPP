#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{
 int gd=DETECT,gm,x,y,x1,y1,r;
 float dp;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();
 cout<<"\nEnter Radius Of Circle\n";
 cin>>r;
 x=0;y=r;dp=3-2*r;
 do
 {
  putpixel(x+200,y+200,4);
  putpixel(x+200,-y+200,4);
  putpixel(-x+200,y+200,4);
  putpixel(-x+200,-y+200,4);
  putpixel(y+200,x+200,4);
  putpixel(y+200,-x+200,4);
  putpixel(-y+200,x+200,4);
  putpixel(-y+200,-x+200,4);
  if(dp<=0)
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