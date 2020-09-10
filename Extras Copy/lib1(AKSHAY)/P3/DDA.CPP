#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
void main()
{
 int gd=DETECT,gm;
 float dx,dy,x,y,x1,y1,x2,y2,i,length;

 cout<<"Enter the co-ordinates of first point\n";
 cin>>x1>>y1;
 cout<<"Enter the co-ordinate of second point\n";
 cin>>x2>>y2;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 dx=abs(x2-x1);
 dy=abs(y2-y1);
 if(dx>=dy)
 {
  length=dx;
 }
 else
 {
  length=dy;
 }
 dx=dx/length;
 dy=dy/length;
 x=x1+0.5;
 y=y1+0.5;
 i=1;
 while(i<=length)
 {
  putpixel(x,y,WHITE);
  x=x+dx;
  y=y+dy;
  i=i+1;
  delay(10);
 }
 getch();
 closegraph();
}