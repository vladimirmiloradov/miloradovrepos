#pragma once
#include<iostream>

class matr
{
private:
	int cols;
	int rows;
	double* elems; 
public:
	matr();
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	~matr();

	double input(); //вещественный
	double input2(); //вещественный
	bool input3(); //бинарный
	bool input3(int i, int j);
	bool input3(int i, int j, double* arr);
	void print();
	double get_elem(int i, int j);
	double sum(const matr* matr2); 
	double sum(int i, int j, const double* arr);
	bool mult(const matr* matr2); 
	bool mult(int i, int j, const double* arr);
	double trace();
	double det();
	void mult_by_num();
};