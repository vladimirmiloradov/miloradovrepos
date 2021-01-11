#include <iostream>
#include "matr2.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");

	//След матрицы
	cout << "След матрицы:" << endl;
	matr matrA;
	matrA.input3d_1();
	cout << "Matr: " << endl;
	matrA.print();
	matrA.trace();
	cout << endl;

	//Определитель матрицы. Частный случай: матрица 2x2 и матрица 3x3.
	cout << "Определитель матрицы:" << endl;
	matr matrB;
	matrB.input3d_1();
	cout << "Matr: " << endl;
	matrB.print();
	matrB.det();
	cout << endl;

	//Сложение матриц
	cout << "\nСложение матриц\nВведите одинаковое количество строк в первой матрице, а затем во второй\n";
	matr matrC, matrD, matrY;
	matrC.input3d_1();
	matrD.input3d_2();
	cout << "Matr1:\n";
	matrC.print();
	cout << "Matr2:\n";
	matrD.print();
	matrY = matrC + matrD;
	cout << "Result:\n";
	matrY.print();

	//Вычитание матриц
	cout << "Вычитание матриц\nВведите одинаковое количество строк в первой матрице, а затем во второй\n";
	matr matrE, matrF, matrX;
	matrE.input3d_1();
	matrF.input3d_2();
	cout << "Matr1:\n";
	matrE.print();
	cout << "Matr2:\n";
	matrF.print();
	matrX = matrE - matrF;
	cout << "Result:\n";
	matrX.print();
	//cout << "matr1:\n" << matrE << endl;
	//matr matrT(matrE);
	//cout << matrT;

	//Умножение матриц
	cout << "Умножение матриц\nВведите одинаковое количество строк в первой матрице, а затем во второй\n";
	matr matrG, matrH, matrZ;
	matrG.input3d_1();
	matrH.input3d_2();
	cout << "Matr1:\n";
	matrG.print();
	cout << "Matr2:\n";
	matrH.print();
	matrZ = matrG * matrH;
	cout << "Result:\n";
	matrZ.print();

	//Матрица с +
	cout << "Вывод матрицы\nВведите количество строк в матрице\n";
	matr matrI;
	matrI.input3d_1();
	cout << "Matr:\n";
	matrI.print();
	matrI = +matrI;
	cout << "Result:\n";
	matrI.print();

	//Обратная матрица
	cout << "Вывод матрицы с обратными значениями\nВведите количество строк в матрице\n";
	matr matrJ;
	matrJ.input3d_1();
	cout << "Matr:\n";
	matrJ.print();
	matrJ = -matrJ;
	cout << "Result:\n";
	matrJ.print();

	//Ввод матрицы
	cout << "Перегрузка ввода\nВведите количество строк в матрице(чем меньше, тем быстрее)\n";
	matr matrK;
	matrK.input0();
	cout << "Matr:\n";
	matrK.print();
	cout << "Введите элементы матрицы:\n";
	cin >> matrK;
	cout << "Result:\n";
	matrK.print();

	//Вывод матрицы
	cout << "Перегрузка вывода\nВведите количество строк в матрице\n";
	matr matrL;
	matrL.input3d_1();
	cout << "Matr:\n";
	matrL.print();
	cout << "Out:\n";
	cout << matrL;
}