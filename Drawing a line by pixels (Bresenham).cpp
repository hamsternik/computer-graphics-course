// Bresenham. Drawing a line by pixels.

#include <iostream>
#include <graphics.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    putpixel(x2, y2, 2); // GREEN
    while(x1 != x2 || y1 != y2) {
        putpixel(x1, y1, 2);
        const int error2 = error * 2;
        if(error2 > -deltaY) {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) {
            error += deltaX;
            y1 += signY;
        }
    }

}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    //setcolor(WHITE);
   //line (x1 + 10, y1, x2 + 10, y2);

    drawLine(x1, y1, x2, y2);


    system("PAUSE");

}
