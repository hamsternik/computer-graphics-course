#include <graphics.h>
#include <process.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void Graph_Init();
void Graph_Close();
void BrezenhamCircle();
void drawCircle(int x, int y, int xc, int yc);
void CorrectInput(int &, int &, int &);

int main()
{
	Graph_Init();
	BrezenhamCircle();
	Graph_Close();
}

/////////////////////////Function describe///////////////////////////////

void Graph_Init() {
    int g_driver = DETECT, g_mode, ErrorCode;
    initgraph(&g_driver, &g_mode, "");
    ErrorCode = graphresult();
    if (ErrorCode != grOk) {
        cout << " graphics error! " << grapherrormsg(ErrorCode) << endl;
        cout << " press any key to start! " << endl;
        exit(1);
    }
}

void Graph_Close() {
    	system("PAUSE");
    	closegraph();
}

void BrezenhamCircle() {
    	int x_centr,y_centr, x_start, y_start;
	int delta, radius;
    	CorrectInput(x_centr, y_centr, radius);
	delta = 3 - radius * 2;
    	x_start = 0;
    	y_start = radius;
	drawCircle(x_start, y_start, x_centr, y_centr);
	while(x_start < y_start) {
		if(delta <= 0) {
			delta = delta + (4*x_start) + 6;
			drawCircle(++x_start,y_start,x_centr,y_centr);
		} else {
			delta = delta + (4 * (x_start - y_start)) + 10;
			drawCircle(++x_start, --y_start, x_centr, y_centr);
		}
	}
}

void CorrectInput(int &x_centr, int &y_centr, int &radius) {
	cout << "Please, enter central coordinates of the circle: "; 	// The best input are
    	cin >> x_centr >> y_centr; 					// x = 250, y = 200, radius = 100
    	while (x_centr < 0 || y_centr < 0) {
        	cout << "Please, enter right coordinates (x and y >= 0): ";
        	cin >> x_centr >> y_centr;
    	}
	cout << "Please, enter circle radius : ";
    	cin >> radius;
    	while (radius <= 0) {
        	cout << "Please, re enter right circle radius(r >= 0):";
        	cin >> radius;
    	}
}

void drawCircle(int x_st, int y_st, int x_c, int y_c) {
	putpixel(x_st + x_c, y_st + y_c, 1);
	putpixel(-x_st + x_c, y_st + y_c, 2);
	putpixel(x_st + x_c, -y_st + y_c, 3);
	putpixel(-x_st + x_c, -y_st + y_c, 4);
	putpixel(y_st + x_c, x_st + y_c, 5);
	putpixel(y_st + x_c, -x_st + y_c, 6);
	putpixel(-y_st + x_c, x_st + y_c, 7);
	putpixel(-y_st + x_c, -x_st + y_c, 8);
	
	Sleep(60);
}
