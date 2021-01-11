#include "circle.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void circle::print_circle()
{
	if (x >= 0 && y >= 0) cout << "��������� ����� (x - " << x << ")^2 + (y - " << y << ")^2 = " << radius << "^2\n";
	else if (x >= 0 && y < 0) cout << "��������� ����� (x - " << x << ")^2 + (y + " << -y << ")^2 = " << radius << "^2\n";
	else if (x < 0 && y >= 0) cout << "��������� ����� (x + " << -x << ")^2 + (y - " << y << ")^2 = " << radius << "^2\n";
	else if (x < 0 && y < 0) cout << "��������� ����� (x + " << -x << ")^2 + (y + " << -y << ")^2 = " << radius << "^2\n";
	cout << "���������� ������ �����: (" << -x << ";" << -y << ")\n"
		<< "������: " << radius << endl;
}
