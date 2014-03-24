#include <iostream>

#define INSIDE 0;
#define LEFT 1;
#define RIGHT 2;
#define BOTTOM 4;
#define TOP 8;

int x0, y0, x1, y1;
int x_min, y_min, x_max, y_max;

int bit_coordinates(int x, int y) {
	int bit_coordinate = INSIDE;
	if (x < x_min) {bit_coordinate |= LEFT;}
	else if (x > x_max) {bit_coordinate |= RIGHT;}
	if (y < y_min) {bit_coordinate |= BOTTOM;}
	else if (y > y_max) {bit_coordinate |= TOP;}
	return bit_coordinate;
}

int main() {
	std::cout << "Введите координаты начала и конца окна: ";
	std::cin >> x_min >> y_min >> x_max >> y_max;
	std::cout  << "Введите координаты начала и конца отрезка: ";
	std::cin >> x0 >> y0 >> x1 >> y1;
	
	std::cout << "Координаты начала отрезка в битовом представлении: " << bit_coordinates(x0, y0);
	std::cout << std::endl << "Координаты конца отрезка в битовом предствалении: " << bit_coordinates(x1, y1);
}
