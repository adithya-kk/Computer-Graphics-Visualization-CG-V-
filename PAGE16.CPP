#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void simple(int x,int y,int,int,int);
void dot(int x,int y,int,int,int);
void dotdashed(int x,int y,int,int,int);
void dashed(int x,int y,int,int,int);

void main()
{
 int gd=DETECT,gm,x1,x2,y1,y2,s1,s2,i,m,ch;
 float dx,dy,x,y,len;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cout<<"\nEnter x1: ";
 cin>>x1;
 cout<<"\nEnter y1: ";
 cin>>y1;
 cout<<"\nEnter x2: ";
 cin>>x2;
 cout<<"\nEnter y2: ";
 cin>>y2;

 x1=x1+320;
 x2=x2+320;
 y1=y1+240;
 y2=y2+240;

 dx=abs(x2-x1);
 dy=abs(y2-y1);
 if(dx>dy)
  len=dx;
 else
  len=dy;
 dx=(x2-x1)/len;
 dy=(y2-y1)/len;
 if((2-x1)>0)
  s1=1;
 else if((x2-x1)<0)
  s1=-1;
 else
  s1=0;
 if((y2-y1)>0)
  s2=1;
 else if((y2-y1)<0)
  s2=-1;
 else
  s2=0;
 x=x1+0.5*s1;
 y=y1+0.5*s2;
 do
 {
  cout<<"\n*********MENU**********\n1.Continuous Line\n2.Dotted Line\n3.Dashed Line\n4.Dot-Dashed Line\n5.Exit\n";
  cout<<"\nEnter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1:	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		line(320,0,320,480);
		line(0,240,640,240);
		simple(x,y,dx,dy,len);
		break;
   case 2:	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		line(320,0,320,480);
		line(0,240,640,240);
		dot(x,y,dx,dy,len);
		break;
   case 3:	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		line(320,0,320,480);
		line(0,240,640,240);
		dashed(x,y,dx,dy,len);
		break;
   case 4:	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		line(320,0,320,480);
		line(0,240,640,240);
		dotdashed(x,y,dx,dy,len);
		break;
   default:	cout<<"\nEnter A Valid Choice\n";
  }
 }while(ch!=5);
}

void dotdashed(int x,int y,int dx,int dy,int len)
{
 int i,m;
 for(i=1;i<=len;i++)
 {
  m=i%10;
  if(m==0)
  {
   putpixel(x,y,15);
   x=x+dx;
   y=y+dy;
  }
  else if(m>=3&&m<=7)
  {
   putpixel(x,y,15);
   x=x+dx;
   y=y+dy;
  }
  else
  {
   x=x+dx;
   y=y+dy;
  }
 }
}

void dot(int x,int y,int dx,int dy,int len)
{
 int i,m;
 for(i=1;i<=len;i++)
 {
  m=i%10;
  if(m==0)
  {
   putpixel(x,y,15);
   x=x+dx;
   y=y+dy;
  }
  else
  {
   x=x+dx;
   y=y+dy;
  }
 }
}

void dashed(int x,int y,int dx,int dy,int len)
{
 int i,m;
 for(i=1;i<=len;i++)
 {
  m=i%10;
  if(m>=3&&m<=7)
  {
   putpixel(x,y,15);
   x=x+dx;
   y=y+dy;
  }
  else
  {
   x=x+dx;
   y=y+dy;
  }
 }
}

void simple(int x,int y,int dx,int dy,int len)
{
 int i;
 for(i=1;i<=len;i++)
 {
  putpixel(x,y,15);
  x=x+dx;
  y=y+dy;
 }
}


