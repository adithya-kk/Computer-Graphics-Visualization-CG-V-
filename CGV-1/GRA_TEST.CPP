#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

class Pixel
{
 public:
	Pixel(int x1,int y1)
	{
	 putpixel(x1,y1,RED);
	}
};

class Line
{
 public:
	Line(int x1,int y1,int x2,int y2)
	{
	 setcolor(2);
	 line(x1,y1,x2,y2);
	}
};

class Circle
{
 public:
	Circle(int x1,int y1,int r)
	{
	 setcolor(1);
	 circle(x1,y1,r);
	}
};

class Ellipse
{
 public:
	Ellipse(int x1,int y1,int sa,int ea,int xr,int yr)
	{
	 ellipse(x1,y1,sa,ea,xr,yr);
	}
};

void main()
{
 clrscr();
 int gd=DETECT,gm,x1,y1,x2,y2,r,xr,yr,sa,ea,n,a,i,color,pixel,maxx,maxy;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi\\");
 int c1,c;
 do
 {
  cout<<"Enter Your Choice: 1>Pixel 2>Line 3>Circle 4>Ellipse 5.Smiley 6>Exit "<<endl;
  cin>>c;
  switch(c)
  {
   case 1:      cout<<"Enter coordinates of pixel: ";
		cin>>x1>>y1;
		Pixel(x1,y1);
		break;

   case 2:	cout<<"Enter coordinates of line(x1,y1,x2,y2): ";
		cin>>x1>>y1>>x2>>y2;
		Line(x1,y1,x2,y2);
		break;

   case 3:	cout<<"Enter radius & coordinates of circle(x1,y1,r): ";
		cin>>x1>>y1>>r;
		Circle(x1,y1,r);
		break;

   case 4:	cout<<"Enter x&y coordinates and start&end angles and x&y radius of Ellipse: ";
		cin>>x1>>y1>>sa>>ea>>xr>>yr;
		Ellipse(x1,y1,sa,ea,xr,yr);
		break;

   case 5:	  setbkcolor(DARKGRAY);//set the background color
		  maxx=getmaxx();//get maximum value for x co-ordinate
		  maxy=getmaxy();//get maximum value for y co-ordinate
		  setcolor(YELLOW);//color for drawing shapes
		  circle(maxx/2,maxy/2,20);//draw a circle
		  setfillstyle(1,YELLOW);//the style to fill the area
		  fillellipse(maxx/2,maxy/2,100,100);//fill the ellipse with color(face)
		  pixel=getpixel(1,1);
		  setfillstyle(1,pixel);
		  setcolor(pixel);
		  fillellipse(maxx/2-50,maxy/2-30,10,10);//fill the ellipse with color(eye)
		  fillellipse(maxx/2+50,maxy/2-30,10,10);//fill the ellipse with color(eye)
		  ellipse(maxx/2,maxy/2,220,320,60,60);//draw an ellipse(mouth)
		  line(maxx/2,maxy/2-10,maxx/2,maxy/2+20);//draw a line(nose)
		  break;

   case 6:	exit(0);
		break;
   default:	cout<<"Enter a valid choice"<<endl;
  }
 cout<<"Enter 0 to continue: ";
 cin>>c1;
 clrscr();
 }
 while(c1==0);
 getch();
}