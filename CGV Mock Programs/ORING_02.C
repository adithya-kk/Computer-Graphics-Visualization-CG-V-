#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main()
{
int i=0,j=0,k=0,l=0,m=0,ch;
float pi=3.1424,a,b,c,d,e;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
printf("\n\nEnter 1 or 2 ");
scanf("%d",&ch);
printf("\n\nYou have entered %d",ch);
getch();
clrscr();
switch(ch)
{
case 1 : while(i<360)
{
a=(pi/180)*i;
setcolor(3);
circle(120+100*sin(a),150-100*cos(a),10);
i++;
delay(5);
}
while(j<360)
{
b=(pi/180)*j;
setcolor(0);
circle(280+100*sin(b),150-100*cos(b),10);
j++;
delay(5);
}
while(k<360)
{
c=(pi/180)*k;
setcolor(4);
circle(440+100*sin(c),150-100*cos(c),10);
k++;
delay(5);
}
while(l<360)
{
d=(pi/180)*l;
setcolor(14);
circle(200+100*sin(d),300-100*cos(d),10);
l++;
delay(5);
}
while(m<360)
{
e=(pi/180)*m;
setcolor(2);
circle(370+100*sin(e),300-100*cos(e),10);
m++;
delay(5);
}

break;
case 2 : while(i<360)
{
a=(pi/180)*i;
setcolor(3);
circle(120+100*sin(a),150-100*cos(a),10);
i++;
delay(5);
}
while(l<360)
{
d=(pi/180)*l;
setcolor(14);
circle(200+100*sin(d),300-100*cos(d),10);
l++;
delay(5);
}
while(j<360)
{
b=(pi/180)*j;
setcolor(0);
circle(280+100*sin(b),150-100*cos(b),10);
j++;
delay(5);
}
while(k<360)
{
c=(pi/180)*k;
setcolor(4);
circle(440+100*sin(c),150-100*cos(c),10);
k++;
delay(5);
}
while(m<360)
{
e=(pi/180)*m;
setcolor(2);
circle(370+100*sin(e),300-100*cos(e),10);
m++;
delay(5);
}

break;
default:
setcolor(13);
outtextxy(190,220,"YOU HAVE ENTERED THE WRONG CHOICE!!");
}
getch();
}

