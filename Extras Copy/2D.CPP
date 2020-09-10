#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void reflx(float a[10][3], float b[3][3], int n);
void axis(int x, int y);
void main()
{
	int gd=DETECT, gm,i,j,k,y,x,n,op;
	float a[10][3], b[3][3],c[10][3];
	char str[20];
	initgraph (&gd,&gm,"C:\\turboc3\\bgi");
	axis(x,y);
	printf("\nEnter no of vertices :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the coordinates :");
		scanf("%f%f",&a[i][0], &a[i][1]);
		a[i][2]=1;
	}
	setcolor(BLUE);
	while(1)
	{
		printf("\n1.Reflection about x axis\n2. Exit\n\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			reflx(a,b,n);
			break;
			case 2:
			exit(0);
			break;
		}
	}
}
void axis (int x,int y)
{
		int i;
		char str[30];
		line(320,0,320,480);
		line(0,240,640,240);
		outtextxy(632,237,">");
		outtextxy(1,237,"<");
		outtextxy(317,1,"^");
		outtextxy(317,472,"v");

		for(i=8,y=0;i>-8;i--,y=y+30)
		{
			setcolor(3);
			line(316,y,324,y);
			if(i==0)
				continue;
			itoa(i,str,10);
			setcolor(WHITE);
			outtextxy(328,y,str);
		}
		for(i=-10,x=20;i<10;i++,x=x+30)
		{
			setcolor(3);
			line(x,236,x,244);
			itoa(i,str,10);
			setcolor(WHITE);
			outtextxy(x,248,str);
		}
}

void reflx(float a[10][3],float b[3][3],int n)
{
	int i,j,k,x,y;
	float c[10][3];
	char str[30];
	axis(x,y);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0],240-30*a[i][1],320+30*a[(i+1)%n][0],240-30*a[(i+1)%n][1]);
	}
	for(i=-10,x=20;i<=10;i++,x=x+30)
	{
		setcolor(3);
		line(x,236,x,244);
		itoa(i,str,10);
		setcolor(WHITE);
		outtextxy(x,248,str);
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			b[i][j]=1;
			else
			{
				b[i][j]=0;
			}
		}
	}
	b[1][1]=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
	setcolor(YELLOW);
	for(i=0;i<n;i++)
	{
		line(320+30*c[i][0],240-30*c[i][1],320+30*c[(i+1)%n][0],240-30*c[(i+1)%n][1]);
	}
}
