#include <graphics.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

void GraphInit();
void GraphClose();
void kov(double A, double B, double C, double D, double n);

int main() {
	int N;
    	cout << "Please, enter iteration's amount: "; cin >> N;
	// here must be chek for correct input

	GraphInit();

      	setcolor(WHITE);
      	rectangle(90, 10, 550, 470);
      	kov(90, 10, 550, 470, N);

	GraphClose();

}

void GraphInit() {
	srand(time(NULL));
	int g_driver = DETECT, g_mode, ErrorCode;
	initgraph(&g_driver, &g_mode, "");
	ErrorCode = graphresult();
	if (ErrorCode != grOk) {
		cout << "graphics error!" << grapherrormsg(ErrorCode) << endl;
		cout << " press any key to start! " << endl;
		exit(1);
	}
}

void GraphClose() {
	system("PAUSE");
	closegraph();
}

void kov(double A,double B,double C,double D,double n) {
	setcolor(rand() % 10 + 1);
	double A1, B1, C1, D1;
	if(n > 0) {
		A1 = 2 * A / 3 + C / 3;
	      	C1 = A / 3 + 2 * C / 3;
	      	B1 = 2 * B / 3 + D / 3;
	      	D1 = B / 3 + 2 * D / 3;

	      	rectangle (A1, B1, C1, D1);
	      
		kov(A, B, A1, B1, n-1);
	      	kov(A1, B, C1, B1, n-1);
	      	kov(C1, B, C, B1, n-1);
	      	kov(A, B1, A1, D1, n-1);
	     	kov(C1, B1, C, D1, n-1);
	      	kov(A, D1, A1, D, n-1);
	      	kov(A1, D1, C1, D, n-1);
	      	kov(C1, D1, C, D, n-1);
	}
}

