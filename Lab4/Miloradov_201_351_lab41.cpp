#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
// Задание 1. Палиндром
void Palindrom(char* cstr1, int len, bool& flag) {  
	for (int i = 1; i < len; i++) { // Преобразование всех букв в строке к прописным
		if ((cstr1[i] > 64) && (cstr1[i] < 91))
			cstr1[i] += 32;
	}

	cout << endl;
	int j;
	for (int i = 1; i < len; i++) { // Цикл удаление пробелов
		if (cstr1[i] == ' '){
			for (j=i; j<len;j++)  {
				cstr1[j] = cstr1[j + 1];
			}
			len--;
		}
	}

	for (int i = 1; i <= len / 2;i++) // Проверка на палиндром
	{
		if (cstr1[i] == cstr1[len - i])
			flag = true;
		else {
			flag = false;
			break;
		}
	}
}

// Задание 2. Оператор FIND
int find_substring() {
	int k = 0, j = 1, m = 0;
	static char cstr3[255];
	char cstr3_1[255];
	char cstr3_2[100];
	cout << "Введите строку с точкой на конце: ";
	cin.getline(cstr3_1, 255, '.');
	cout << "Введите подстроку с точкой на конце: ";
	cin.getline(cstr3_2, 100, '.');
	for (int i = 1; i < strlen(cstr3_1); i++)
	{
		if (cstr3_1[i] == cstr3_2[j])
		{
			for (j = 1; j < strlen(cstr3_2); j++)
			{
				if (cstr3_2[j] == cstr3_1[i])
				{
					cstr3[k] = cstr3_2[j];
					m = k + 1;
					k++;
					i++;
				}
				else
				{
					static char cstr3[255] = {};
					k = 0;
					break;
				}
			}
			j = 1;
			cstr3[m] = ' ';
			k++;
		}
	}
	printf("Нашлось:%s\n", cstr3);
	return 0;
	}

// Задание 3. Шифр Цезаря
void cesar(char* cstr2, int len2) { // Преобразование строки по шифру Цезаря
	for (int i = 0; i < len2; i++) {
		cstr2[i] = cstr2[i] + 3;
		cout << cstr2[i];
	}
}

// Задание 4. 
int Zadanie4() {
	static char cstr4[255];
	char cstr4_1[255];
	int k = 0;
	cout << "Введите текст:";
	cin.getline(cstr4_1, 255, '.');
	for (int i = 1; i < strlen(cstr4_1); i++)
	{
		if (cstr4_1[i] == '"')
		{
			i++;
			for (;;)
			{
				if (cstr4_1[i] == '"')
				{
					cstr4[k] = ' ';
					k++;
					break;
				}
				else
				{
					cstr4[k] = cstr4_1[i];
					k++;
					i++;
				}
			}
		}
	}
	printf("Символы в ковычках: %s\n", cstr4);
	k = 0;
	return 0;
}
// Меню
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	bool flag = true;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n";
		cout << "1. задание 1\n";
		cout << "2. задание 2\n";
		cout << "3. задание 3\n";
		cout << "4. задание 4\n";
		cout << "5. выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			char cstr1[255];
			cout << "Введите строку на английском языке c точкой в конце: ";
			cin.getline(cstr1, 255, '.');
			cout << endl;
			int len;
			len = strlen(cstr1);
			Palindrom(cstr1, len, flag);
			if (flag == true)
				cout << "Является палиндромом\n";
			else
				cout << "Не является палиндромом\n";
			cout << endl;
			break;
		}
		case 2:
		{
			find_substring();
			break;
		}
		case 3:
		{
			char cstr2[255];
			cout << "Введите строку c точкой в конце: ";
			cin.getline(cstr2, 255, '.');
			int len2;
			len2 = strlen(cstr2);
			cesar(cstr2, len2);
			cout << endl;
			break;
		}
		case 4:
		{
			Zadanie4();
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}
