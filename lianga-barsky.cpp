#include <iostream>
#include <graphics.h>
#include <locale.h>

#define SIZE 4

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int gd=DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_line_first, y_line_first, x_line_last, y_line_last;
    int x_max, y_max, x_min, y_min;
    int x_sm_line_first, y_sm_line_first, x_sm_line_last, y_sm_line_last;
    int mas_P[SIZE], mas_Q[SIZE];
    double t1, t2;
    double t[SIZE];

    cout << "Введите нижние координаты окна: " << endl;
    cin >> x_min >> y_min;
    cout << "Введите вверхние координаты окна: " << endl;
    cin >> x_max >> y_max;
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    cout << "Введите начальное значение координаты точки прямой по абсцисе: " << endl;
    cin >> x_line_first;
    cout << "Введите начальное значение координаты точки прямой по ординате: " << endl;
    cin >> y_line_first;
    cout << "Введите конечное значение координаты точки прямой по абсцисе: " << endl;
    cin >> x_line_last;
    cout << "Введите конечное значение координаты точки прямой по ординате: " << endl;
    cin >> y_line_last;

    line(x_line_first, y_line_first, x_line_last, y_line_last);

    int Dx = x_line_last - x_line_first;
    int Dy = y_line_last - y_line_first;

    mas_P[0] = -1 * Dx;
    mas_P[1] = Dx;
    mas_P[2] = -1 * Dy;
    mas_P[3] = Dy;

    mas_Q[0] = x_line_first - x_min;
    mas_Q[1] = x_max - x_line_first;
    mas_Q[2] = y_line_first - y_min;
    mas_Q[3] = y_max - y_line_first;

    for (int i = 0; i < SIZE; ++i) {
        if (mas_P[i] != 0)
            t[i] = (double)mas_Q[i] / mas_P[i];
        else if (mas_P[i] == 0 && mas_Q[i] < 0) {
            cout << "Линия полностью находится за окном!" << endl;
            //system("PAUSE");
        }
        else if (mas_P[i] == 0 && mas_Q[i] >= 0) {
            cout << "Линия полностью находится в выделеном окне!" << endl;
            //system("PAUSE");
        }
    }

    t[0] > t[2] ? t1 = t[0] : t1 = t[2];
    t[1] < t[3] ? t2 = t[1] : t2 = t[3];

    if (t1 < t2) {
        x_sm_line_first = x_line_first + t1 * Dx;
        y_sm_line_first = y_line_first + t1 * Dy;
        x_sm_line_last = x_line_first + t2 * Dx;
        y_sm_line_last = y_line_first + t2 * Dy;

        setcolor(GREEN);
        line(x_sm_line_first, y_sm_line_first, x_sm_line_last, y_sm_line_last);
        system("PAUSE");
    }
    else {
       cout << "Линия выходит из выделеного окна" << endl;
        system("PAUSE");
    }
}
