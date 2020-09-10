#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main()
{
 int gd=DETECT,gm;
 float x,y,x1,y1,x2,y2,dx,dy,e,i;
 cout<<"Enter the frist co-ordinates\n";
 cin>>x1>>y1;
 cout<<"Enter the second co-ordinates\n";
 cin>>x2>>y2;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 e=2*dy-dx;
 x=x1;
 y=y1;
 do
 {
  putpixel(x,y,WHITE);
  while(e>=0)
  {
   y=y+1;
   e=e-2*dx;
  }
  x=x+1;
  e=e+2*dy;
  i=i+1;
  delay(10);
 }while(i<=dx);
 getch();
 closegraph();
}