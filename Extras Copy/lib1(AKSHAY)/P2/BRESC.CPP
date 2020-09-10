#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
void main()
{
 int gd=DETECT,gm,x,y,r;
 float dp;
 cout<<"Enter the radius of circle\n";
 cin>>r;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 x=0;
 y=r;
 dp=3-2*r;
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
    dp=dp+(4*(x-y))+10;
    y--;
   }
   x++;
   delay(100);
  }while(x<=y);
 getch();
 closegraph();
}