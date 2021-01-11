
#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    setlocale(LC_ALL,"Russian");
    std::stack<char> stack;
    std::string stroka;
    cout << "Введите строку" << endl;
    cin >> stroka;
    for (int i = 0; i < stroka.length(); i++) {
        if ((stroka[i] == '(') || (stroka[i] == '[') || (stroka[i] == '{'))
            stack.push(stroka[i]);
        if (stroka[i] == ')')
            if (stack.top() == '(')
                stack.pop();
            else {
                cout << "Знаки расставлены неправильно!" << endl;
                break;
            }
        if (stroka[i] == ']')
            if (stack.top() == '[')
                stack.pop();
            else {
                cout << "Знаки расставлены неправильно!" << endl;
                break;
            }
        if (stroka[i] == '}')
            if (stack.top() == '{')
                stack.pop();
            else {
                cout << "Знаки расставлены неправильно!" << endl;
                break;
            }
    }
    if (stack.empty()) cout << "Знаки расставлены верно!" << endl;
}

