#include <iostream>
#include <cmath>
#include <graphics.h>
#include <locale.h>

using namespace std;

void DrawPixelLine (int x1, int y1, int x2, int y2);

int main()
{
    setlocale(LC_ALL, "RUS");

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    cout << "¬ведите координаты начала и конца пр€мой: ";
    cin >> x1 >> y1 >> x2 >> y2;

    DrawPixelLine(x1, y1, x2, y2);
    system("PAUSE");
}

void DrawPixelLine (int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int incX = x2 < x1 ? -1 : x2 > x1 ? 1 : 0;
    int incY = y2 < y1 ? -1 : y2 > y1 ? 1 : 0;

    int plusX, plusY, el, es;
    if (dx > dy) {
        plusX = incX;
        plusY = 0;
        el = dx;
        es = dy;
    }
    else {
        plusX = 0;
        plusY = incY;
        el = dy;
        es = dx;
    }

    int pogresh = el / 2;
    int x_start = x1;
    int y_start = y1;
    putpixel(x_start, y_start, 2);
    setcolor(WHITE);
    line(x_start, y_start, x2, y2);

    int t = 0;
    for (int t = 0; t <= el; ++t) {
        pogresh -= es;
        if (pogresh < 0) {
            pogresh += el;
            x_start += incX;
            y_start += incY;
        }
        else {
            x_start += plusX;
            y_start += plusY;
        }
        putpixel(x_start, y_start, 2);
        setcolor(WHITE);
        line(x_start, y_start, x2, y2);
    }

}
