
#include <iostream>
#include "matr.h"


using std::cout;
using std::cin;
using std::endl;


int main()
{
	setlocale(LC_ALL, "Russian");
	//Сложение матриц
	cout << "Сложение матриц:" << endl;
	matr matrA, matrB;
	matrA.input();
	matrB.input2();
	cout << "Matr 1:" << endl;
	matrA.print();
	cout << "Matr 2:" << endl;
	matrB.print();
	matrA.sum(&matrB);
	cout << "Sum:\n ";
	matrA.print();
	cout << endl;

	//Умножение матриц
	cout << "Умножение матриц:" << endl;
	matr matrC, matrD;
	matrC.input3();
	matrD.input3();
	cout << "Matr 1:" << endl;
	matrC.print();
	cout << "Matr 2:" << endl;
	matrD.print();
	matrC.mult(&matrD);
	cout << "Mult:\n ";
	matrC.print();
	cout << endl;

	//След матрицы
	cout << "След матрицы:" << endl;
	matr matrE;
	matrE.input2();
	cout << "Matr: " << endl;
	matrE.print();
	matrE.trace();
	cout << endl;

	//Определитель матрицы. Частный случай: матрица 2x2 и матрица 3x3.
	cout << "Определитель матрицы:" << endl;
	matr matrH;
	matrH.input();
	cout << "Matr: " << endl;
	matrH.print();
	matrH.det();
	cout << endl;

	//Умножение матрицы на число
	cout << "Умножение матрицы на число" << endl;
	matr matrF;
	matrF.input2();
	cout << "Matr: " << endl;
	matrF.print();
	matrF.mult_by_num();
	cout << "Mult by num:\n";
	matrF.print();
	return 0;
}