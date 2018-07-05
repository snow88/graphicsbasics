#include<iostream>
#include<graphics.h>

using namespace std;

void ellipse(int xc, int yc, int a, int b)
{
    int x=a, y=0, d=(b*b/4)-a*b*b+a*a;
    while( b*b*abs(x)>= a*a*abs(y))
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if(d<0)
            d+=2*a*a*y+3*a*a;
        else{
            d+=2*b*b-2*x*b*b+2*a*a*y+3*a*a;
            x--;
        }
        y++;
    }
    d=b*b*(x-1)*(x-1)+a*a*(y+0.5)*(y+0.5)-a*a*b*b;
    while(x>=0)
    {
        putpixel(x+xc,y+yc,WHITE);
        putpixel(-x+xc,y+yc,WHITE);
        putpixel(-x+xc,-y+yc,WHITE);
        putpixel(x+xc,-y+yc,WHITE);

        if (d<0)
        {
            d+=3*b*b-2*x*b*b+2*a*a+2*y*a*a;
            y++;
        }
        else
            d+=3*b*b-2*x*b*b;
        x--;
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    ellipse(100, 50, 80, 30);

    getch();
    closegraph();
    return 0;
}
