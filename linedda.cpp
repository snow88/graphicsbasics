#include<iostream>
#include<graphics.h>
using namespace std;

void myline (int x1, int y1, int x2, int y2, int lcolor)
{
    float x=x1;
    float y=y1;
    float dx = x2-x1;
    float dy = y2-y1;

    //vertical line
    if (dx==0)
    {
        if (dy>0)
        {
            while(y<=y2)
            {
                putpixel(x,y,lcolor);
                y++;
            }
        }
        else
        {
            while(y>=y2)
            {
                putpixel(x,y,lcolor);
                y--;
            }
        }
        return;
    }

    float m = dy/dx;

    //case1 + horizontal line
    if (m>=0 && x2>=x1 && y2>=y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x<=x2)
            {
                y+=m;
                x++;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y<=y2)
            {
                x+=1/m;
                y++;
                putpixel(x,y,lcolor);
            }
        }
    }

    //case2
    else if (m<0 && x2>x1 && y2<y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x<=x2)
            {
                y+=m;
                x++;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y>=y2)
            {
                x-=1/m;    //since m is -ve
                y--;
                putpixel(x,y,lcolor);
            }
        }
    }

    //case3 + horizontal backward line
    else if (m<=0 && x2<=x1 && y2>=y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x>=x2)
            {
                y-=m;
                x--;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y<=y2)
            {
                x+=1/m;
                y++;
                putpixel(x,y,lcolor);
            }
        }
    }

    //case4
    else if (m>0 && x2<x1 && y2<y1)
    {
        if(abs((int)dy)<abs((int)dx))
        {
            putpixel(x,y,lcolor);
            while(x>=x2)
            {
                y-=m;
                x--;
                putpixel(x,y,lcolor);
            }
        }
        else
        {
            putpixel(x,y,lcolor);
            while(y>=y2)
            {
                x-=1/m;
                y--;
                putpixel(x,y,lcolor);
            }
        }
    }
}

int main()
{
    int gd=DETECT, gm=0;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    myline(10, 20, 50, 70, WHITE);

    getch();
    closegraph();
    return 0;
}
