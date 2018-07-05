#include<iostream>
#include<graphics.h>
using namespace std;

void parabola(int xc, int yc, int a)
{
int x=0;
int y=0;
int d = 1-2*a;
while (abs(x)<2*a)
{
 putpixel(x+xc,y+yc,WHITE);
 putpixel(-x+xc,y+yc,WHITE);

 if(d<=0)
 {
  d+=3+2*x;
 }
 else
 {
  d+=3+2*x-4*a;
  y++;
 }
 x++;
}

d = (x+1/2)*(x+1/2) - 4*a*(y+1);
while(y<100)                     //controls height of parabola
{
 putpixel(x+xc,y+yc,WHITE);
 putpixel(-x+xc,y+yc,WHITE);

 if(d<=0)
 {
  d+=2+2*x-4*a;
  x++;
 }
 else
 {
  d+=-4*a;
 }
 y++;
}

}

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 parabola(100, 40, 20);

 getch();
 closegraph();
 return 0;
}

