#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <graphics.h>
#include <ctime>

void GraphInit();
void GraphClose();
void DrawSierpinskiTriangle();

int main() 
{
	GraphInit();
	DrawSierpinskiTriangle();
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

void DrawSierpinskiTriangle() {
	char Direct;
	int iterate;
 	unsigned int x1, y1, x2, y2;
 	x1 = x2 = 320;
	y1 = y2 = 0;
	for(iterate = 0; iterate < 100000; iterate++) {
  		Direct = rand() % 3;
  		
		if(Direct == 0) {
   			x1 = (x2 + 320) / 2;
   			y1 = (y2 + 0) / 2;
  		}
  		else if(Direct == 1) {
   			x1 = (x2 + 0) / 2;
   			y1 = (y2 + 480) / 2;
  		}
  		else if(Direct == 2) {
   			x1 = (x2 + 640) / 2;
   			y1 = (y2 + 480) / 2;
  		}
  		
		putpixel(x1, y1, WHITE);
  		
		x2 = x1;
  		y2 = y1;
 	}
}

