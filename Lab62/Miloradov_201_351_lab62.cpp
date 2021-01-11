
#include <iostream>
#include <deque>
#include <string>

using std::cout;
using std::cin;
using std::endl;
int main()
{
    setlocale(LC_ALL, "Russian");
    std::deque<char> deque;
    char stroka[255];
    cout << "Введите строку" << endl;
    std::cin.getline(stroka,255);
    int len;
    len = strlen(stroka);
    int j;
    for (int i = 0; i < len; i++) { // Цикл удаление пробелов
        if (stroka[i] == ' ') {
            for (j = i; j < len; j++) {
                stroka[j] = stroka[j + 1];
            }
            len--;
        }
    }
    for (int i = 0; i < len; i++) { // Преобразование всех букв в строке к прописным
        if ((stroka[i] > 64) && (stroka[i] < 91))
            stroka[i] += 32;
    }
    cout << endl;
    for (int i = 0; i <= len; i++)   // Добавление элементов в дэк
        deque.push_front(stroka[i]);
    deque.pop_front();
    for (int i = 0; i < len/2; i++) {  // Проверка на палиндром
        if (deque.front() == deque.back()) {
            deque.pop_front();
            deque.pop_back();
        }
        else {
            cout << "Строка не является палиндромом!" << endl;
            break;
        }
    }
    if (deque.empty()) cout << "Строка является палиндромом!" << endl;
}

