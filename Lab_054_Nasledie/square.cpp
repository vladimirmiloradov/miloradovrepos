#include "square.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

std::pair<int, int> square::corner_square()
{
    int x_corner = x + length_of_side;
	int y_corner = y - length_of_side;
	return std::pair<int, int>(x_corner, y_corner);
}

void square::print_square()
{
	cout << "Координаты левой верхней точки квадрата: (" << x << ";" << y << ")\n"
		<< "Длина стороны: " << length_of_side << "\n"
		<< "Координаты правой нижней точки: (" << corner_square().first << ";" << corner_square().second << ")\n\n"
		<< "Примерный квадрат из точек:" << endl;
	for (int i = 0; i < length_of_side; i++) {
		for (int j = 0; j < length_of_side; j++)
			cout << ". ";
		cout << endl;
	}
	cout << endl;
}