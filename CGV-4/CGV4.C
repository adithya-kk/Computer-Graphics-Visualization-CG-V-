#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void dotdashed(int x,int y,int,int,int);
void main()
{
 int gd=DETECT,gm,x1,x2,y1,y2,s1,s2,i,m,ch;
 float dx,dy,x,y,len;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("\nEnter x1: ");
 scanf("%d",&x1);
 printf("\nEnter y1: ");
 scanf("%d",&y1);
 printf("\nEnter x2: ");
 scanf("%d",&x2);
 printf("\nEnter y2: ");
 scanf("%d",&y2);
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
 if((x2-x1)>0)
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
  printf("\n*******************MENU*******************\n");
  printf("\n1- dot-dashed");
  printf("\n2- exit");
  printf("\nenter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	line(320,0,320,480);
	line(0,240,640,240);
	dotdashed(x,y,dx,dy,len);
  }
 }while(ch!=2);
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
getch();





