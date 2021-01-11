#include "matr2.h"

matr::matr()
{
	rows = 0;
	elems = nullptr;
}

matr::matr(const matr& matr1)
{
	rows = matr1.rows;
	elems = new double[rows * rows];
	for (int k = 0; k < rows * rows; k++)
		elems[k] = matr1.elems[k];
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}

double matr::input3d_1()
{
	std::cout << "Input number of rows:";
	std::cin >> rows;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * rows]{ 0 };
	//верхн€€ диагональ
	for (int i = 1; i < rows * rows; i += rows + 1) elems[i] = i * 37 % 9;
	//главна€ диагональ
	for (int i = 0; i < rows * rows; i += rows + 1) elems[i] = i * 36 % 7;
	//нижн€€ диагональ
	for (int i = rows; i < rows * rows; i += rows + 1) elems[i] = i * 33 % 6;
	return 0.0;
}

double matr::input3d_2()
{
	std::cout << "Input number of rows:";
	std::cin >> rows;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * rows]{ 0 };
	//верхн€€ диагональ
	for (int i = 1; i < rows * rows; i += rows + 1) elems[i] = i * 27 % 8;
	//главна€ диагональ
	for (int i = 0; i < rows * rows; i += rows + 1) elems[i] = i * 26 % 7;
	//нижн€€ диагональ
	for (int i = rows; i < rows * rows; i += rows + 1) elems[i] = i * 23 % 6;
	return 0.0;
}

double matr::input0()
{
	std::cout << "Input number of rows:";
	std::cin >> rows;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * rows]{ 0 };
	return 0.0;
}


void matr::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			std::cout << get_elem(i, j) << "\t";
		std::cout << std::endl;
	}
}

double matr::get_elem(int i, int j)
{
	return elems[i * rows + j];
}

double matr::trace()
{
	double k = 0;
	for (int i = 0; i < rows * rows; i = i + rows)
	{
		k = k + elems[i];
		i += 1;
	}
	std::cout << "Summa elementov po diagonali: " << k << std::endl;
	return true;
}

double matr::det()
{
	double det1;
	double det2;
	if ((rows != 2) && (rows != 3))
		std::cout << "Error! Programm couldn't complete operation.";
	else {
		if (rows == 2) {
			det1 = elems[0] * elems[3] - elems[1] * elems[2];
			std::cout << det1;
		}
		if (rows == 3) {
			det2 = elems[0] * elems[4] * elems[8] + elems[6] * elems[1] * elems[5] + elems[3] * elems[7] * elems[2] - elems[6] * elems[4] * elems[2] - elems[0] * elems[7] * elems[5] - elems[3] * elems[1] * elems[8];
			std::cout << det2;
		}

	}
	return true;
}

matr operator+(const matr& left, const matr& right)
{
	matr buffer(left);
	for (int i = 0; i < left.rows * left.rows; i++)
		buffer.elems[i] += right.elems[i];
	return buffer;
}

matr operator-(const matr& left, const matr& right)
{
	matr buffer(left);
	//std::cout << buffer;
	for (int i = 0; i < left.rows * left.rows; i++)
		buffer.elems[i] = left.elems[i] - right.elems[i];
	//std::cout << buffer;
	return buffer;
}

matr operator*(const matr& left, const matr& right)
{
	matr buff(left);
	for (int i = 0; i < right.rows; i++)
	{
		for (int j = 0; j < right.rows; j++)
		{
			buff.elems[i * buff.rows + j] = 0;

			for (int q = 0; q < right.rows; q++)
			{
				buff.elems[i * buff.rows + j] += left.elems[i * buff.rows + q] * right.elems[q * right.rows + j];
			}
		}
	}
	return buff;
}

std::ostream& operator<<(std::ostream& out, const matr& matrix)
{
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.rows; j++)
			out << matrix.elems[i * matrix.rows + j] << "\t";
		std::cout << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, const matr& matrix)
{
	//верхн€€ диагональ
	std::cout << "\n¬ведите элементы верхней диагонали:\n";
	for (int i = 1; i < matrix.rows * matrix.rows; i += matrix.rows + 1) in >> matrix.elems[i];
	//главна€ диагональ
	std::cout << "\n¬ведите элементы главной диагонали:\n";
	for (int i = 0; i < matrix.rows * matrix.rows; i += matrix.rows + 1) in >> matrix.elems[i];
	//нижн€€ диагональ
	std::cout << "\n¬ведите элементы нижней диагонали:\n";
	for (int i = matrix.rows; i < matrix.rows * matrix.rows; i += matrix.rows + 1) in >> matrix.elems[i];
	return in;
}

matr& operator+(matr& matrix) { return matrix; };

matr& operator-(matr& matrix)
{
	for (int i = 0; i < matrix.rows * matrix.rows; i++)
	{
		if (matrix.elems[i] == 0) continue;
		matrix.elems[i] = -matrix.elems[i];
	}
	return matrix;
}