#include <iostream>
#include "square.h"
#include "circle.h"
#include "Position.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");
    /*Объявление для ввода координат квадрата, круга и их хар-ик*/
    int x, y, x0, y0, r, len;
    cout << "Введите координаты левого верхнего угла квадрата: ";
    cin >> x >> y;
    cout << "Введите длину стороны квадрата: ";
    cin >> len;
    cout << "-------------------------------------" << endl;
    //Создание квадрата с заданными координатами
    square sq1(x, y, len);
    sq1.corner_square();
    sq1.print_square();
    cout << "-------------------------------------" << endl;
    cout << "Введите координаты сдвига круга: ";
    cin >> x0 >> y0;
    cout << "Введите радиус круга: ";
    cin >> r;
    //Создание круга с заданными координатами
    circle cr1(x0, y0, r);
    cr1.print_circle();
}