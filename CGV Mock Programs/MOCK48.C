//;hut by flood fill algorithm(roll no:48)
#include<graphics.h>
#include<conio.h>
int main()
{
int gd = DETECT,gm;
initgraph(&gd, &gm, "C:\\TC\\BGI");
setcolor(WHITE);
rectangle(150,180,250,300);
rectangle(250,180,420,300);
rectangle(180,250,220,300);
line(200,100,150,180);
line(200,100,250,180);
line(200,100,370,100);
line(370,100,420,180);
setfillstyle(SOLID_FILL, BROWN);
floodfill(152, 182, WHITE);
delay(50);
floodfill(252, 182, WHITE);
delay(65);
setfillstyle(SLASH_FILL, GREEN);
 delay(75);
floodfill(182, 252, WHITE);
 delay(85);
setfillstyle(HATCH_FILL, RED);
  delay(90);
floodfill(200, 105, WHITE);
  delay(100);
floodfill(210, 105,WHITE);
delay(105);
getch();
closegraph();
delay(50);																																																																																																																																return 0;
}