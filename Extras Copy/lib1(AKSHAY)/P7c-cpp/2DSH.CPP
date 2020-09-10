#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<math.h> 
 
int x1,y1,x2,y2,x,y,x3,y3,x4,y4,ch;
void main()
{
  int gd = DETECT,gm;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
      cout<<"enter the value of line coordinates:";
      cin>>x1>>y1>>x2>>y2;
      cout<<"enter the value of shearing for x-axis:";
      cin>>x;
      cout<<"enter the value of shearing for y-axis:";
      cin>>y;
      cleardevice();
      setcolor(4);
      line(x1,y1,x2,y2);
      cout<<"now hit a key to see shear in x_axis:";
      getch();
      setcolor(1);
      line(x1,y1,x2*x,y2);
      cout<<"\nnow hit a key to see shear in y_axis:";
      getch();
      setcolor(58);
      line(x1,y1,x2,y2*y);
      getch();
      closegraph();
}