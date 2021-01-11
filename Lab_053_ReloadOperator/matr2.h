#pragma once
#include<iostream>

class matr
{
private:
	int rows;//number of rows
	double* elems; // elements
public:
	matr();
	matr(const matr& matr1);
	~matr();
	double input3d_1();//ввод первой 3ех диагональной матрицы
	double input3d_2();//ввод второй 3ех диагональной матрицы
	double input0();//ввод матрицы из нулей
	void print();
	double get_elem(int i, int j);
	double trace();
	double det();
	//перегрузка бинарных
	friend matr operator+(const matr& left, const matr& right);
	friend matr operator-(const matr& left, const matr& right);
	friend matr operator*(const matr& left, const matr& right);
	//перегрузка ввода-вывода
	friend std::ostream& operator<<(std::ostream& out, const matr& matrix);
	friend std::istream& operator>>(std::istream& in, const matr& matrix);
	//перегрузка унарных
	friend matr& operator+(matr& matrix);
	friend matr& operator-(matr& matrix);
};
