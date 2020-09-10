#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>

void main()
{

	    int gd=DETECT,gm;
	    int x1,x2,x3,x4,y1,y2,y3,y4,rx,ry;
	    int nx1,nx2,nx3,nx4,ny1,ny2,ny3,ny4;
	    float t;
	    clrscr();

	    printf("\n\t Enter the points  x1,y1\n");
	    scanf("%d%d",&x1,&y1);
	    printf("\n\t Enter the points  x2,y2\n");
	    scanf("%d%d",&x2,&y2);
	    printf("\n\t Enter the points  x3,y3\n");
	    scanf("%d%d",&x3,&y3);
	    printf("\n\t Enter the points of x4,y4\n");
	    scanf("%d%d",&x4,&y4);
	    printf("\n\t Enter the points for about whic polygon rotate \n");
	    scanf("%d%d",&rx,&ry);


	    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	    printf("Enter the rotation angle\n");
	    scanf("%f",&t);
	    t=t*(3.14/180.0);

	    nx1=rx+(x1-rx)*cos(t)-(y1-rx)*sin(t);
	    ny1=ry+(x1-ry)*sin(t)+(y1-ry)*cos(t);

	    nx2=rx+(x2-rx)*cos(t)-(y2-rx)*sin(t);
	    ny2=ry+(x2-ry)*sin(t)+(y2-ry)*cos(t);

	    nx3=rx+(x3-rx)*cos(t)-(y3-rx)*sin(t);
	    ny3=ry+(x3-ry)*sin(t)+(y3-ry)*cos(t);

	    nx4=rx+(x4-rx)*cos(t)-(y4-rx)*sin(t);
	    ny4=ry+(x4-ry)*sin(t)+(y4-ry)*cos(t);



	    line(x1,y1,x2,y2);
	    line(x2,y2,x3,y3);
	    line(x3,y3,x4,y4);
	    line(x4,y4,x1,y1);
	    getch();

	    line(nx1,ny1,nx2,ny2);
	    line(nx2,ny2,nx3,ny3);
	    line(nx3,ny3,nx4,ny4);
	    line(nx4,ny4,nx1,ny1);
	    getch();
	    closegraph();
}

