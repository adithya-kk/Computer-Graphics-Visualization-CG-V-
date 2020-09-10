#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void boundaryf(int x,int y,int fill,int boundary)
{
	int c;
	c=getpixel(x,y);
	if(c!=boundary && c!=fill)
	{
		putpixel(x,y,fill);
		boundaryf(x+1,y,fill,boundary);
		boundaryf(x-1,y,fill,boundary);
		boundaryf(x,y+1,fill,boundary);
		boundaryf(x,y-1,fill,boundary);
	}
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setcolor(6);
	rectangle(25,25,90,90);
	boundaryf(55,55,6,15);
	getch();
	closegraph();
}
