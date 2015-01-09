#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

void GraphInit();
void GraphClose();
void Koch(int iter, double x1, double y1, double x2, double y2);

int main() {

	GraphInit();

        int n;
        cout << "Please, enter number of iterations for Koch snowflake: "; cin >> n;
        Koch(n, 300, 10, 110, 356);
        Koch(n, 500, 356, 300, 10);
        Koch(n, 110, 356, 500, 356);

	GraphClose();
}

void GraphInit() {
	int g_driver = DETECT, g_mode, ErrorCode;
        initgraph(&g_driver, &g_mode, "");
	ErrorCode = graphresult();
	if (ErrorCode != grOk) {
		cout << " graphics error! " << grapherrormsg(ErrorCode) << endl;
		cout << " press any key to start! " << endl;
		exit(1);
	}
}

void GraphClose() {
	system("PAUSE");
	closegraph();
}

void Koch(int iter, double x1, double y1, double x2, double y2) {
	double deltaX, deltaY, x3, y3, x4, y4, x5, y5;
    	if (!iter)
		line(x1, y1, x2, y2);
    	else {
        	deltaX = x2 - x1;
        	deltaY = y2 - y1;

        	x3 = x1 + deltaX / 3;
        	y3 = y1 + deltaY / 3;

        	x4 = 0.5 * (x1+x2) + sqrt(3) * (y1 - y2) / 6;
        	y4 = 0.5 * (y1+y2) + sqrt(3) * (y2 - y1) / 6;

        	x5 = x1 + 2 * deltaX / 3;
        	y5 = y1 + 2 * deltaY / 3;

        	Koch(iter-1, x1, y1, x3, y3);
        	Koch(iter-1, x3, y3, x4, y4);
        	Koch(iter-1, x4, y4, x5, y5);
	}
}

