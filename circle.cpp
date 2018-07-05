#include<iostream>
#include<graphics.h>
using namespace std;

void circlemidpt(int xc, int yc, int r)
{
int x=r;
int y=0;
putpixel(x+xc,y+yc,WHITE);
if(r>0)
{
  putpixel(x+xc,-y+yc,WHITE);
  putpixel(y+xc,x+yc,WHITE);
  putpixel(-y+xc,x+yc,WHITE);
}
int d=1-r;
while (x>y)
{
 y++;
 if(d<=0)
 d+=2*y+1;
 else
 {d+=2*(y-x)+1;
 x--;
 }
 if(x<y)
 break;

 putpixel(x+xc,y+yc,WHITE);
 putpixel(-x+xc,y+yc,WHITE);
 putpixel(x+xc,-y+yc,WHITE);
 putpixel(-x+xc,-y+yc,WHITE);

 if(x!=y)
 { putpixel(y+xc,x+yc,WHITE);
 putpixel(-y+xc,x+yc,WHITE);
 putpixel(y+xc,-x+yc,WHITE);
 putpixel(-y+xc,-x+yc,WHITE);
 }

}
}

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 circlemidpt(30, 40, 20);

 getch();
 closegraph();
 return 0;
}
