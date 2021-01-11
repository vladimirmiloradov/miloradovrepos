#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;
void InputMassiv(int * &arr, int *arr_size) { //Ввод массива
	if (arr != nullptr) delete[] arr;
	cout << "Введите размер массива: ";
	cin >> *arr_size;
	arr = new int[*arr_size];
	for (int i = 0; i < *arr_size; i++) {
		cin >> arr[i];
	}
}
void OutputMassiv(int* arr, const int arr_size) { //Вывод массива
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << ' ';
	cout << std::endl;
}
void SortirovkaPoSumme(int* arr, int arr_size) { //Сортировка массива по сумме цифр на чётных местах
	int i = 0;
	int q = 0;
	bool flag;
	int num, number;
	int* arr2 = new int[arr_size] {0};
	while (i < arr_size) {
		string intStr = to_string(arr[i]);
		q = intStr.length();
		num = arr[i];
		flag = false;
		if (q == 1) {
			arr2[i] = num;
			flag = true;
		}
		while (q != 0 && flag == false) {
			number = num % 10;
			num /= 10;
			if (!(q % 2))
				arr2[i] = arr2[i] + number;
			q--;
		}
		i++;
	}
	for (int i = 0; i < arr_size; i++) {
		for (int j = i + 1; j < arr_size; j++) {
			if (arr2[j] < arr2[i]) {
				swap(arr[i], arr[j]);
				swap(arr2[i], arr2[j]);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int* arr = nullptr;
	int arr_size = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n";
		cout << "1. задание 1\n";
		cout << "2. задание 2\n";
		cout << "3. задание 3\n";
		cout << "4. выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			InputMassiv(arr, &arr_size);
			break;
		}
		case 2:
		{
		    OutputMassiv(arr, arr_size);
			break;
		}
		case 3:
		{
			cout << "Введите размер массива";
			cin >> arr_size;
			arr = new int[arr_size];
			for (int i = 0; i < arr_size; i++) {
				cin >> arr[i];
			}
			cout << endl;
			SortirovkaPoSumme(arr, arr_size);
			for (int j = 0; j < arr_size; j++) {
				cout << arr[j] << " ";
			}
			cout << endl;
			delete[] arr;
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}