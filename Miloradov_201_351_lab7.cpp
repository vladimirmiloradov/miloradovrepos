#include <locale.h>
#include <iostream>
#include <vector>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct MyStruct
{
	string Surname;
	string Name;
	int Age;
};

template <typename SomeType> void sort(vector<SomeType>& arr, int select, int first, int last)
{
	if (select == 1) // по фамилии
	{
		int f = first, l = last;
		MyStruct mid = arr[(f + l) / 2]; // вычисление опорного элемента
		do
		{
			while (arr[f].Surname < mid.Surname) f++;
			while (arr[l].Surname > mid.Surname) l--;
			if (f <= l) //перестановка элементов
			{
				std::swap(arr[f], arr[l]);
				f++;
				l--;
			}
		} while (f <= l);
		if (first < l) sort(arr, select, first, l);
		if (f < last) sort(arr, select, f, last);
	}
	if (select == 2) // по имени
	{
		int f = first, l = last;
		MyStruct mid = arr[(f + l) / 2]; // вычисление опорного элемента
		do
		{
			while (arr[f].Name < mid.Name) f++;
			while (arr[l].Name > mid.Name) l--;
			if (f <= l) //перестановка элементов
			{
				std::swap(arr[f], arr[l]);
				f++;
				l--;
			}
		} while (f <= l);
		if (first < l) sort(arr, select, first, l);
		if (f < last) sort(arr, select, f, last);
	}
	if (select == 3) // по возрасту
	{
		int f = first, l = last;
		MyStruct mid = arr[(f + l) / 2]; // вычисление опорного элемента
		do
		{
			while (arr[f].Age < mid.Age) f++;
			while (arr[l].Age > mid.Age) l--;
			if (f <= l) //перестановка элементов
			{
				std::swap(arr[f], arr[l]);
				f++;
				l--;
			}
		} while (f <= l);
		if (first < l) sort(arr, select, first, l);
		if (f < last) sort(arr, select, f, last);
	}
}

void output(vector<MyStruct>& arr)
{
	for (auto i : arr)
		cout << i.Surname << "\t" << i.Name << "\t" << i.Age << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");
	int n; // количество учеников в классе
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	cout << "Введите количество учеников в классе: ";
	cin >> n;
	cout << endl;
	vector <MyStruct> arrsort(n);
	int first = 0, last = n - 1;
	cout << "Заполните данные для сортировки:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Surname: ";
		cin >> arrsort[i].Surname;
		cout << "Name: ";
		cin >> arrsort[i].Name;
		cout << "Age: ";
		cin >> arrsort[i].Age;
		cout << endl;
	}
	while (true) // непрерывный цикл
	{
		std::cout << "Что вы хотите выполнить? \n"
			<< "1. Сортировка по фамилии;\n"
			<< "2. Сортировка по имени;\n"
			<< "3. Сортировка по возрасту;\n"
			<< "4. Вывод данных;\n"
			<< "5. Выход.\n";

		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			sort(arrsort, choice, first, last);
			break;
		}
		case 2:
		{

			sort(arrsort, choice, first, last);
			break;
		}
		case 3:
		{

			sort(arrsort, choice, first, last);
			break;
		}
		case 4:
		{
			output(arrsort);
			break;
		}
		case 5:
		{
			cout << "До свидания!";
			return 0;
		}
		default:
			cout << "Такого номера нет.\nПопробуйте снова:" << endl;
		}
	}
}
