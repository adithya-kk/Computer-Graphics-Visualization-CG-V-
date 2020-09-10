#include<stdio.h>
#include<graphics.h>
#include<conio.h>
flood(int,int,int,int);
int main()
{
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
rectangle(50,50,100,100);
flood(55,55,1,15);
getch();
closegraph();
return 0;
}
flood(int seed_x,int seed_y,int f_colour,int b_colour)
{

if(getpixel(seed_x,seed_y)!=b_colour&&getpixel(seed_x,seed_y)!=f_colour)
{
putpixel(seed_x,seed_y,f_colour);
flood(seed_x+1,seed_y,f_colour,b_colour);
flood(seed_x,seed_y+1,f_colour,b_colour);
flood(seed_x-1,seed_y,f_colour,b_colour);
flood(seed_x,seed_y-1,f_colour,b_colour);
flood(seed_x+1,seed_y+1,f_colour,b_colour);
flood(seed_x-1,seed_y-1,f_colour,b_colour);
flood(seed_x+1,seed_y-1,f_colour,b_colour);
flood(seed_x-1,seed_y+1,f_colour,b_colour);
delay(10);
}
}