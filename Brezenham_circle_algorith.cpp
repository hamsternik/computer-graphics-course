#include<iostream>
#include<graphics.h>

using namespace std;

void drawCircle(int x, int y, int xc, int yc);

int main()
{
	int gd = DETECT, gm;
	int r, xc, yc, pk, x, y;
	initgraph(&gd, &gm, "");
	cout<<"Enter the center co-ordinates" << endl;
	cin>>xc>>yc;
	cout<<"Enter the radius of circle" << endl;
	cin>>r;
	pk = 3 - 2*r;
	x=0; y = r;
	drawCircle(x,y,xc,yc);
	while(x < y)
	{
		if(pk <= 0)
		{
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		}
		else
		{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
	}
    system("PAUSE");
    closegraph();
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,1);
	putpixel(-x+xc,y+yc,2);
	putpixel(x+xc, -y+yc,3);
	putpixel(-x+xc, -y+yc, 4);
	putpixel(y+xc, x+yc, 5);
	putpixel(y+xc, -x+yc, 6);
	putpixel(-y+xc, x+yc, 7);
	putpixel(-y+xc, -x+yc, 8);
}
