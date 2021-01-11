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
	double input3d_1();//���� ������ 3�� ������������ �������
	double input3d_2();//���� ������ 3�� ������������ �������
	double input0();//���� ������� �� �����
	void print();
	double get_elem(int i, int j);
	double trace();
	double det();
	//���������� ��������
	friend matr operator+(const matr& left, const matr& right);
	friend matr operator-(const matr& left, const matr& right);
	friend matr operator*(const matr& left, const matr& right);
	//���������� �����-������
	friend std::ostream& operator<<(std::ostream& out, const matr& matrix);
	friend std::istream& operator>>(std::istream& in, const matr& matrix);
	//���������� �������
	friend matr& operator+(matr& matrix);
	friend matr& operator-(matr& matrix);
};
