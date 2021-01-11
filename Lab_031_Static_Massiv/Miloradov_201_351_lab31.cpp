#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void task1(int *arr, int len_arr) //Сортировка пузырьком
{
	int z;
	for (int i = 0; i < len_arr; i++) {
		for (int j = 0; j < len_arr - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				z = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = z;
			}
		}
	}

	for (int i = 0; i < len_arr; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void task2(char *arr2, int N1) //Сортировка подсчётом
{
	int N = 26;
	int j=0;
	int count[26] = { 0 }; 
	for (int i = 0; i < N; i++) {
		count[int(arr2[i] - 'a')]++;
	}
	int i = 0;
	while (j <= 26)
	{
		if (count[j] > 0) {
			arr2[i] = char(int('a')+j);
			i++;
			count[j]--;
		}
		else
			j++;
	}

	for (int i = 0; i < N1; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n";
		cout << "1. задание 1\n";
		cout << "2. задание 2\n";
		cout << "3. выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int arr[1000] = { 0 };
			int len_arr = 0;
			cout << "Введите количество чисел в массиве: ";
			cin >> len_arr;
			for (int i = 0; i < len_arr; i++)
				cin >> arr[i];
			task1(arr,len_arr);
			break;
		}
		case 2:
		{
			char arr2[1000] = {'\0'};
			int N1;
			cout << "Введите количество букв в массиве: ";
			cin >> N1;
			for (int i = 0; i < N1; i++)
				cin >> arr2[i];
			task2(arr2, N1);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}