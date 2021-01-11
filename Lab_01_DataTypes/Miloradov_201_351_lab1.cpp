#include <iostream>
#include <bitset>
#include <limits>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	cout << "1: " << std::endl;
	cout << "Miloradov Vladimir Andreevich, 201-351 " << std::endl;

	cout << "2: " << std::endl;
	cout << "min int= " << INT_MIN << " max int= " << INT_MAX << " size of int= " << sizeof(int) << endl;
	cout << "min unsigned int= " << "***" << " max unsigned int= " << UINT_MAX << " size of unsigned int= " << sizeof(unsigned int) << endl;
	cout << "min short= " << SHRT_MIN << " max short= " << SHRT_MAX << " size of short= " << " size of short= " << sizeof(short) << endl;
	cout << "min unsigned short= " << "***" << " max unsigned short= " << USHRT_MAX << " size of unsigned short= " << sizeof(unsigned short) << endl;
	cout << "min long= " << LONG_MIN << " max long= " << LONG_MAX << " size of long= " << sizeof(long) << endl;
	cout << "min long long= " << LLONG_MIN << " max long long= " << LLONG_MAX << " size of long long= " << sizeof(long long) << endl;
	cout << "min double= " << DBL_MIN << " max double= " << DBL_MAX << " size of double= " << sizeof(double) << endl;
	cout << "min char= " << CHAR_MIN << " max char= " << CHAR_MAX << " size of char= " << sizeof(char) << endl;
	cout << "min bool= " << "false" << " max bool= " << "true" << " size of bool= " << sizeof(bool) << endl;

	setlocale(LC_ALL, "Russian");
	cout << "3: " << std::endl;
	int num;
	cout << "Введите число:" << std::endl;
	cin >> num;
	cout << "\nВ бинарном виде: " << std::bitset<16>(num) << std::endl;
	cout << "В шестнадцатеричном виде: " << hex << num << endl;
	char ch = static_cast<char>(num);
	cout << "Char = " << ch << endl;
	bool res = (bool)num;
	cout << "Bool = " << res << endl;
	double db = static_cast<double>(num);
	cout << "Double = " << db << endl;

	int a, b;
	cout << "4. Введите коэфиценты a * x = b: " << endl;
	cin >> a >> b;
	cout << endl;
	cout << a << " * x = " << b << endl;
	cout << "x = " << b << " / " << a << endl;
	cout << "x = " << b / a << endl;
	cout << "Ответ: " << double(b) / a << endl;

	cout << "5: " << std::endl;
	int k1, k2;
	cout << "Введите координаты точки на прямой: ";
	cin >> k1 >> k2;
	int center = double(k1 + k2) / 2;
	cout << "Середина отрезка находится в точке с координатой = " << center << endl;
	system("pause");
	return 0;
}