#include<graphics.h>
#include<process.h>
#include <locale.h>
#include<iostream>
#include<cmath>

void Graph_Init();
void Brezenham_circle();

int main() {
    setlocale(LC_ALL, "RUS");
    Graph_Init();
    Brezenham_circle();
    system("PAUSE");
    closegraph();
}

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

void Brezenham_circle() {
int radius, delta, err, sigma, sigma_strih;
    int x, y;
    int x1, y1;
    std::cout << "¬ведите радиус окружности: ";
    std::cin >> radius;
    std::cout << "¬ведите координаты центра: ";
    std::cin >> x >> y;
    x1 = x;
    y1 = y + radius;
    delta = 2 * (1 - radius);
    err = x1; //??????????????
    putpixel(x1, y1, 2);
    while (y1 > err) {
        putpixel(x1, y1, 2);
        if (delta < 0) {
            delta = 2*delta + 2*y1 - 1;
            sigma = 2 * (delta + y1) - 1;
            if (sigma <= 0) {
                --x1;
                delta = delta + 2*x1 + 1;
            }
            else {
                ++x1;
                --y1;
                delta = delta + 2*x1 + 2*y1 + 2;
            }
        }
        else if (delta > 0){
            delta = 2*delta - 2*x1 - 1;
            sigma_strih = 2 * (delta - x1) - 1;
            if (sigma_strih <= 0) {
                ++x1;
                --y1;
                delta = delta + 2*x1 + 2*y1 + 2;
            }
            else {
                --y1;
                delta = delta - 2*y1 + 1;
            }
        }
        else {
            ++x1;
            --y1;
            delta = delta + 2*x1 + 2*y1 + 2;
        }
    ++err;
    }
}
