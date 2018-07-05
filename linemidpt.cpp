#include<iostream>
#include<graphics.h>
using namespace std;

void line_midpt(int x1, int y1, int x2, int y2)
{
int x=x1;
int y=y1;
int dx=x2-x1;
int dy=y2-y1;
float m = (float)dy/dx;

if (m<=1)
{
int d=2*dy-dx;
while (x<=x2)
{
 putpixel(x, y, WHITE);
 if(d<=0)
  d+=2*dy;
 else
 {d+=2*(dy-dx);
  y++;
 }
 x++;
}
}

else
{
int d=dy-2*dx;
while (y<=y2)
{
 putpixel(x, y, WHITE);
 if(d>=0)
  d+=-2*dx;
 else
 {d+=2*(dy-dx);
  x++;
 }
 y++;
}
}

}

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 line_midpt(10, 10, 60, 40);

 getch();
 closegraph();
 return 0;
}

