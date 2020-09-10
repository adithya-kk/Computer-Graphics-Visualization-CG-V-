#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
	int gdriver=DETECT,gmode,i=0,j=0;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	for(i;i<420;++i)
	{
	circle(65,230,20);
	circle(175,230,40);
	line(65,210,175,190);
	line(65,250,175,270);

	pieslice(65,230,359-j,360-j,20);
	pieslice(65,230,179-j,180-j,20);
	pieslice(65,230,89-j,90-j,20);
	pieslice(65,230,269-j,270-j,20);

	pieslice(175,230,359-j,360-j,40);
	pieslice(175,230,179-j,180-j,40);
	pieslice(175,230,89-j,90-j,40);
	pieslice(175,230,269-j,270-j,40);

	if(j==179)
	j=0;
	++j;

	delay(10);
	cleardevice();

	}
	closegraph();
	getch();
}