#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void flood(int,int,int,int);
void main()
{
int gd=DETECT,gm;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
rectangle(50,50,100,100);
flood(55,55,10,15);
getch();
}
void flood(int x,int y,int fill_col,int old_col)
{
	if(getpixel(x,y)!=fill_col && getpixel(x,y)!=old_col)
	{
		putpixel(x,y,fill_col);

		delay(10);
		putpixel(x,y,fill_col);
		flood(x+1,y,fill_col,old_col);
		flood(x-1,y,fill_col,old_col);
		flood(x,y+1,fill_col,old_col);
		flood(x,y-1,fill_col,old_col);
	}
}
