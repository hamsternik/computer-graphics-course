#include <graphics.h>
#include <process.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void Graph_Init();
void Graph_Close();
void Brezenham_circle();
void drawCircle(int x, int y, int xc, int yc);
void CorrectInput(int &, int &, int &);

int main()
{
    	setlocale(LC_ALL, "RUS");
	Graph_Init();
	Brezenham_circle();
	Graph_Close();
}

/////////////////////////Function describe///////////////////////////////

void Graph_Init() {
    int g_driver = DETECT, g_mode, ErrorCode;
    initgraph(&g_driver, &g_mode, "");
    ErrorCode = graphresult();
    if (ErrorCode != grOk) {
        std::cout << " graphics error! " << grapherrormsg(ErrorCode) << std::endl;
        std::cout << " press any key to start! " << std::endl;
        exit(1);
    }
}

void Graph_Close() {
    system("PAUSE");
    closegraph();
}

void Brezenham_circle() {
    	int x_centr,y_centr, x_start, y_start;
    	int delta, radius;
    	CorrectInput(x_centr, y_centr, radius);
	delta = 3 - 2*radius;
    	x_start = 0;
    	y_start = radius;
	drawCircle(x_start, y_start, x_centr, y_centr);
	while(x_start < y_start)
	{
		if(delta <= 0)
		{
			delta = delta + (4*x_start) + 6;
			drawCircle(++x_start,y_start,x_centr,y_centr);
		}
		else
		{
			delta = delta + (4 * (x_start - y_start)) + 10;
			drawCircle(++x_start, --y_start, x_centr, y_centr);
		}
	}
}

void CorrectInput(int &x_centr, int &y_centr, int &radius) {
// The best input are:
//      for x = 250, for y = 200
//      for radius = 100
    	cout << "Введите координаты центра круга: " << endl;
    	cin >> x_centr >> y_centr;
    	while (x_centr < 0 || y_centr < 0) {
        cout << "Введите корректные данные (координаты круга): ";
        cin >> x_centr >> y_centr;
    }
	cout << "¬ведите радиус круга: " << endl;
    	cin >> radius;
    	while (radius <= 0) {
        	cout << "Введите корректные данные (радиус):";
        	cin >> radius;
    }
}

void drawCircle(int x_st, int y_st, int x_c, int y_c)
{
	putpixel(x_st + x_c, y_st + y_c, 1);
	putpixel(-x_st + x_c, y_st + y_c, 2);
	putpixel(x_st + x_c, -y_st + y_c, 3);
	putpixel(-x_st + x_c, -y_st + y_c, 4);
	putpixel(y_st + x_c, x_st + y_c, 5);
	putpixel(y_st + x_c, -x_st + y_c, 6);
	putpixel(-y_st + x_c, x_st + y_c, 7);
	putpixel(-y_st + x_c, -x_st + y_c, 8);
	Sleep(15);
}
