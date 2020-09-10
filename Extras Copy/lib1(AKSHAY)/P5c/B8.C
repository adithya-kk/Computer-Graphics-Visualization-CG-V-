#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void boundaryf(int x,int y,int f_colour,int b_colour)
{
	int c;
	c=getpixel(x,y);
	if(c!=b_colour && c!=f_colour)
	{
		putpixel(x,y,f_colour);
		boundaryf(x+1,y,f_colour,b_colour);
		boundaryf(x,y+1,f_colour,b_colour);
		boundaryf(x-1,y,f_colour,b_colour);
		boundaryf(x,y-1,f_colour,b_colour);
		boundaryf(x+1,y+1,f_colour,b_colour);
		boundaryf(x-1,y-1,f_colour,b_colour);
		boundaryf(x+1,y-1,f_colour,b_colour);
		boundaryf(x-1,y+1,f_colour,b_colour);
	}
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setcolor(4);
rectangle(50,50,100,100);
boundaryf(55,55,4,15);
getch();
closegraph();
}
