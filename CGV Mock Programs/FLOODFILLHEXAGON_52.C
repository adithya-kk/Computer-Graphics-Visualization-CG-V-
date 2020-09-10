#include<stdio.h>
#include<conio.h>
#include<graphics.h>
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

void main()
{
int gd=DETECT,gm;
int np=4,hex[14]={400,50,450,50,500,100,450,150,400,150,350,100,400,50};
initgraph(&gd,&gm,"c:\\turboc3\\BGI");
np=7;
setcolor(4);
drawpoly(np,hex);
flood(402,102,RED,YELLOW);
flood(502,452,RED,YELLOW);

getch();

closegraph();
}