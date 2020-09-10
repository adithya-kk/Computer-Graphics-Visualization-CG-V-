#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

void translate(float a[10][3], float b[3][3], int n);
void scale(float a[10][3], float b[3][3], int n);
void rotate(float a[10][3], float b[3][3], int n);
void reflo(float a[10][3], float b[3][3], int n);
void reflx(float a[10][3], float b[3][3], int n);
void xshear(float a[10][3], float b[3][3], int n);
void yshear(float a[10][3], float b[3][3], int n);
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
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0], 240-30*a[i][1],320+30*a[(i+1)%n][0],240-30*a[(i+1)%n][1]);
	}
	while(1)
	{
		printf("\nMenu\n\n1. Translation\n2. Scaling\n3.Rotation\n4. Reflection about origin\n5.Reflection about x axis\n6. X shear\n 7.Y shear\n8. Exit\n\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			cleardevice ();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			translate(a,b,n);
			break;

			case 2:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			scale(a,b,n);
			break;

			case 3:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			rotate(a,b,n);
			break;

			case 4:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			reflo(a,b,n);
			break;

			case 5:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			reflx(a,b,n);
			break;

			case 6:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			xshear(a,b,n);
			break;

			case 7:
			cleardevice();
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			yshear(a,b,n);
			break;

			case 8:
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
void translate(float a[10][3], float b[3][3], int n)
{
		int tx,ty,i,j,k,x,y;
		float c[10][3];
		char str[30];
		axis(x,y);
		setcolor(BLUE);
		for(i=0;i<n;i++)
		{
			line(320+30*a[i][0], 240-30*a[i][1], 320+30*a[(i+1)%n][0], 240-30*a[(i+1)%n][1]);
		}
		printf("\n Input values of tx and ty:");
		scanf("%d%d",&tx,&ty);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i==j)
					b[i][j]=1;
				else
					b[i][j]=0;
			}
		}
		b[2][0]=tx;
		b[2][1]=ty;
		for(i=0;i<n;i++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}

	setcolor(YELLOW);
	for(i=0;i<n;i++)
	{
		line(320+30*c[i][0],240+30*c[i][1],320+30*c[(i+1)%n][0],240-30*c[(i+1)%n][1]);
	}
}

void scale(float a[10][3], float b[3][3], int n)
{
	int i,j,k,x,y;
	float c[10][3],sx,sy;
	char str[30];
	axis(x,y);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0], 240-30*a[i][1], 320+30*
		a[(i+1)%n][0], 240*a[(i+1)%n][1]);
	}
	printf("\n Inputvalues of sx and sy:");
	scanf("%f%f",&sx,&sy);
	for(i=0;i<3;i++)
	{
		if(i==j)
			b[i][j]=1;
		else
			b[i][j]=0;
	}

b[0][0]=sx;
b[1][1]=sy;
for(i=0;i<n;i++)
{
	for(j=0;j<3;j++)
	{
		c[i][j]=0;
		for(k=0;k<3;k++)
		{
			c[i][j]=c[i][j] + (a[i][k]*b[k][j]);
		}
	}
}
setcolor(YELLOW);
for(i=0;i<n;i++)
{
	line(320+30*c[i][0],240-30*c[i][j], 320+30*c[(i+1)%n][0],240-30*c[(i+1)%n][1]);
}
}
void rotate(float a[10][3],float b[3][3],int n)
{
	int i,j,k,s1,x,y;
	float t,c[10][3];
	char ch,str[30];
	axis(x,y);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0],240-30*a[i][1],320+30*a[(i+1)%n][0],240-30*a[(i+1)%n][1]);
	}
	printf("\n Input value of theta : ");
	scanf("%f",&t);
	printf("\n(C)lockwise or (A)nticlockwise ? : ");
	flushall();
	scanf("%c",&c);
	if(ch=='a')
	s1=1;
	else
	{
		line(320+30*c[i][0],240-30*c[i][1],320+30*c[(i+1)%n][0],240-30*c[(i+1)%n][1]);
	}
	setcolor(YELLOW);
	for(i=0;i<n;i++)
	{
		line(320+30*c[i][0],240-30*c[i][1],320+30*c[(i+1)%n][0],240-30*c[(i+1)%n][1]);
	}
}
void reflo(float a[10][3],float b[3][3],int n)
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
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			b[i][j]=-1;
			else
			{
				b[i][j]=0;
			}
		}
	}
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
void xshear(float a[10][3],float b[3][3],int n)
{
	int i,j,k,x,y,shx;
	float c[10][3];
	char str[30];
	axis(x,y);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0],240-30*a[i][1],320+30*a[(i+1)%n][0],240-30*a[(i+1)%n][1]);
	}
	printf("\nEnter x shear : ");
	scanf("%d",&shx);
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
	b[1][0]=shx;
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
void yshear(float a[10][3],float b[3][3],int n)
{
	int i,j,k,x,y,shy;
	float c[10][3];
	char str[30];
	axis(x,y);
	setcolor(BLUE);
	for(i=0;i<n;i++)
	{
		line(320+30*a[i][0],240-30*a[i][1],320+30*a[(i+1)%n][0],240-30*a[(i+1)%n][1]);
	}
	printf("\nEnter y shear : ");
	scanf("%d",&shy);
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
	b[0][1]=shy;
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