#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

string file_format(string file_path_full) {
	string format;
	format = file_path_full.substr(file_path_full.rfind('.'));
	cout << format << endl;
	return format;
}

string file_name(string file_path_full) {
	string name;
	name = file_path_full.substr(file_path_full.rfind('\\'));
	name = name.erase(name.find('.'));
	name = name.erase(0,1);
	cout << name << endl;
	return name;
}

string file_path(string file_path_full) {
	string path;
	path = file_path_full.erase(file_path_full.rfind('\\'));
	cout << path << endl;
	return path;
}

char file_disk(string file_path_full, char ch_disk) {
	ch_disk = file_path_full[0];
	cout << ch_disk << endl;
	return ch_disk;
}

bool file_rename(string file_path_full) {
	string rename;
	string format;
	string path;
	string new_name;
	string name;
	name = file_path_full.substr(file_path_full.rfind('\\'));
	name = name.erase(name.find('.'));
	name = name.erase(0, 1);
	format = file_path_full.substr(file_path_full.rfind('.'));
	path = file_path_full.substr(0);
	path=path.erase(path.rfind('\\'));
	path.push_back('\\');
	cout << "Введите новое имя: " << path;
	cin >> new_name;
	cout << endl;
	rename = path + new_name + format;
	cout << "Переименованный файл: " << rename << endl;
	if (new_name != name) {
		cout << "Файл успешно переименован" << endl;
		return true;
	}
	else
	{
		cout << "Использовано старое имя файла" << endl;
		return false;
	}
		
}

bool file_copy(string file_path_full) {
	string dest_path = file_path_full;
	dest_path.insert(file_path_full.rfind('.'), "_copy", 0, 5);
	std::ifstream src(file_path_full, std::ifstream::in);
	if (src.is_open()) {
		std::ofstream dest;
		dest.open(dest_path, std::ofstream::out);
		string line;
		while (!src.eof()) {
			std::getline(src, line);
			dest << line << std::endl;
		}
		dest.close();
		return true;
	}
	else {
		cout << "File not found" << endl;
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	string file_path_full;
	string format;
	string name;
	string path;
	string disk;
	string rename;
	const char* ch_disk = disk.c_str();
	cout << "Введите расположение файла: ";
	getline(cin,file_path_full);
	while (true)
	{
		cout << "Что вы хотите выполнить? \n";
		cout << "1. Расширение\n";
		cout << "2. Имя\n";
		cout << "3. Расположение\n";
		cout << "4. Диск\n";
		cout << "5. Переименование\n";
		cout << "6. Создание копии\n";
		cout << "7. Выход из программы\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			file_format(file_path_full);
			break;
		}
		case 2:
		{
			file_name(file_path_full);
			break;
		}
		case 3:
		{
			file_path(file_path_full);
			break;
		}
		case 4:
		{
			file_disk(file_path_full, *ch_disk);
			break;
		}
		case 5:
		{
			file_rename(file_path_full);
			break;
		}
		case 6:
		{
			file_copy(file_path_full);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}