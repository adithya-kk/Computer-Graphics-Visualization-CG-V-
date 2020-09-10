#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
 int gd=DETECT,gm,i=0,a;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 int x=getmaxx();
 rectangle(50,50,250,75);
  rectangle(50,75,90,150);
  arc(90,75,270,360,30);
  line(90,75,112,95);
  cout<<"press 1 to fire bullet";
  cin>>a;
  if(a==1)
  {
 for(i=0;i<=x;i++)
 {
  rectangle(50,50,250,75);
  rectangle(50,75,90,150);
  arc(90,75,270,360,30);
  line(90,75,95,95);
  rectangle(250+i,60,270+i,70);
  delay(10);
  cleardevice();
 }
 }
 else
 {
 cout<<"wrong choice";
  }
 getch();
closegraph();
}