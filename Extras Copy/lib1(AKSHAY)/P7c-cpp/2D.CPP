#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<math.h>
class transform
{
 private:
  int input[20][2],scalm[2][2];
  int trans[2][2],clockw;
  int ref[2][2];
  float rot[2][2],theta,resmr[20][2];
  int resm[20][2];
  int shear_mat[2][2];
  int edges,scalx,scaly,tx,ty;
  int shx,shy;
 public:
  void xshear();
  void yshear();
  void menu();
  void menu1();
  void accept();
  void scale();
  void translate();
  void rotate();
  void reflect();
  void multiply(int a[20][2],int b[2][2],int c[20][2]);
  void multiplyxx(int a[20][2],int b[2][2],int c[20][2],int edges);
  void multiply1(int a[20][2],float b[2][2],float c[20][2]);
  void plot(int mat[20][2]);
  void plot1(float mat[20][2]);
};
void transform::accept()
{
 int i,j;
 cleardevice();
 cout<<"Enter the number of edges:";
 cin>>edges;
 cout<<"Enter the co-ordinates in matrix form:";
 for(i=1;i<=edges;i++)
 {
  for(j=1;j<=2;j++)
  {
   cout<<"\nA["<<i<<"]["<<j<<"]=";
   cin>>input[i][j];
  }
 }
 for(i=1;i<=edges;i++)
 {
  input[i][1]=input[i][1]+320;
  input[i][2]=240-input[i][2];
 }
 plot(input);
 for(i=1;i<=edges;i++)
 {
  input[i][1]=input[i][1]-320;
  input[i][2]=240-input[i][2];
 }
}
void transform::menu()
{
 int choice;
 cleardevice();
 cout<<"\t\tMenu"
      <<"\n1>Scaling"
      <<"\n2>Translation"
      <<"\n3>Rotate"
      <<"\n4>Shearing"
      <<"\n5>Reflection"
      <<"\nEnter Your Choice\t";
      cin>>choice;
      switch(choice)
      {
       case 1:scale();
	     break;
       case 2:translate();
	     break;
       case 3:rotate();
	     break;
       case 4:menu1();
	     break;
       case 5:reflect();
	     break;
       default:exit(0);
      }
}
void transform::reflect()
{
 int choice,i;
 cleardevice();
 cout<<"\t\tMenu"
      <<"\n1>Reflection About Y axis"
      <<"\n1>Reflection About X axis"
      <<"\n1>Reflection About Origin"
      <<"\nEnter your choice\t";
      cin>>choice;
      switch(choice)
      {
       case 1:ref[1][2]=ref[2][1]=0;
	      ref[1][1]=-1;
	      ref[2][2]=1;
	      break;
       case 2:ref[1][2]=ref[2][1]=0;
	      ref[1][1]=1;
	      ref[2][2]=-1;
	      break;
       case 3:ref[1][2]=ref[2][1]=0;
	      ref[1][1]=-1;
	      ref[2][2]=-1;
	      break;
      }
      accept();
      multiply(input,ref,resm);
      for(i=1;i<=edges;i++)
      {
       resm[i][1]=resm[i][1]+320;
       resm[i][2]=240-resm[i][2];
      }
      plot(resm);
}
void transform::menu1()
{
 int choice;
 cleardevice();
 cout<<"\t\tMenu"
      <<"\n1>X Shear"
      <<"\n2>Y Shear"
      <<"\nEnter Your Choice\t";
 cin>>choice;
 switch(choice)
 {
  case 1:xshear();
	 break;
  case 2:yshear();
	 break;
 }
}
void transform::xshear()
{
 int i,sides;
 accept();
 edges=sides;
 cout<<"\nEnter the x Shear Factor\t";
 cin>>shx;
 shear_mat[1][1]=shear_mat[2][2]=1;
 shear_mat[1][2]=0;
 shear_mat[2][1]=shx;
 multiplyxx(input,shear_mat,resm,sides);
 for(i=1;i<=edges;i++)
 {
  resm[i][1]=resm[i][1]+320;
  resm[i][2]=240-resm[i][2];
 }
 plot(resm);
}
void transform::yshear()
{
 int i,sides;
 accept();
 sides=edges;
 cout<<"\nEnter the y Shear Factor\t";
 cin>>shy;
 shear_mat[1][1]=shear_mat[2][2]=1;
 shear_mat[2][1]=0;
 shear_mat[1][2]=shy;
 multiplyxx(input,shear_mat,resm,sides);
 edges=sides;
 for(i=1;i<=edges;i++)
 {
  resm[i][1]=resm[i][1]+320;
  resm[i][2]=240-resm[i][2];
 }
 plot(resm);
}
void transform::rotate()
{
 int i;
 float theta1;
 accept();
 cout<<"\nEnter the angle of rotation\t";
 cin>>theta;
 cout<<"Enter 1 for clockwise rotation and 0 for anticlockwise";
 cin>>clockw;
 theta1=((3.14*theta)/180);
 if(clockw==1)
 {
  rot[1][1]=rot[2][2]=cos(theta1);
  rot[1][2]=-sin(theta1);
  rot[2][1]=sin(theta1);
 }
 else
 {
  rot[1][1]=rot[2][2]=cos(theta1);
  rot[1][2]=sin(theta1);
  rot[2][1]=-sin(theta1);
 }
 multiply1(input,rot,resmr);
 for(i=1;i<=edges;i++)
 {
  resmr[i][1]=(int)(resmr[i][1]+320);
  resmr[i][2]=(int)(240-resmr[i][2]);
 }
 plot1(resmr);
}
void transform::scale()
{
 int i;
 accept();
 cout<<"\nEnter the Scale X factor\t";
 cin>>scalx;
 cout<<"\nEnter the Scale Y factor\t";
 cin>>scaly;
 scalm[1][1]=scalx;
 scalm[1][2]=scalm[2][1]=0;
 scalm[2][2]=scaly;
 multiply(input,scalm,resm);
 for(i=1;i<=edges;i++)
 {
  resm[i][1]=resm[i][1]+320;
  resm[i][2]=240-resm[i][2];
 }
 plot(resm);
}
void transform::multiply(int a[20][2],int b[2][2],int c[20][2])
{
 int i;
 for(i=1;i<=edges;i++)
 {
  c[i][1]=(a[i][1]*b[1][1])+(a[i][2]*b[2][1]);
  c[i][2]=(a[i][1]*b[1][2])+(a[i][2]*b[2][2]);
 }
}
void transform::multiplyxx(int a[20][2],int b[2][2],int c[20][2],int edges)
{
 int i;
 for(i=1;i<=edges;i++)
 {
  c[i][1]=(a[i][1]*b[1][1])+(a[i][2]*b[2][1]);
  c[i][2]=(a[i][1]*b[1][2])+(a[i][2]*b[2][2]);
 }
}
void transform::multiply1(int a[20][2],float b[2][2],float c[20][2])
{
 int i;
 for(i=1;i<=edges;i++)
 {
  c[i][1]=(a[i][1]*b[1][1])+(a[i][2]*b[2][1]);
  c[i][2]=(a[i][1]*b[1][2])+(a[i][2]*b[2][2]);
 }
}
void transform::plot(int mat[20][2])
{
 int i;
 setcolor(10);
 line(0,240,639,240);
 line(320,0,320,479);
 outtextxy(295,243,"0,0");
 setcolor(WHITE);
 for(i=1;i<edges;i++)
  line(mat[i][1],mat[i][2],mat[i+1][1],mat[i+1][2]);
 line(mat[1][1],mat[1][2],mat[i][1],mat[i][2]);
 getch();
}

void transform::plot1(float mat[20][2])
{
 int i;
 setcolor(10);
 line(0,240,639,240);
 line(320,0,320,479);
 outtextxy(295,243,"0,0");
 setcolor(WHITE);
 for(i=1;i<edges;i++)
  line(mat[i][1],mat[i][2],mat[i+1][1],mat[i+1][2]);
 line(mat[1][1],mat[1][2],mat[i][1],mat[i][2]);
 getch();
}
void transform::translate()
{
 int i,j;
 accept();
 cout<<"\nEnter tx Factor\t";
 cin>>tx;
 cout<<"\nEnter ty Factor\t";
 cin>>ty;
 tx=320-tx;
 ty=240+ty;
 for(i=1;i<=edges;i++)
 {
  input[i][1]=input[i][1]+640-tx;
  input[i][2]=480-input[i][2]-ty;
 }
 plot(input);
}
void main()
{
 char ch;
 int gd=DETECT,gm,i;
 do
 {
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  transform t;
  t.menu();
  closegraph();
  cout<<"Do You Want To Continue(y/n)?\t";
  ch=getche();
 }while(ch=='y'||ch=='Y');
}
