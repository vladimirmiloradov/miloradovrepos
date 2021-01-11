#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

struct spisok
{
    string num_group;
    string surname;
};

int main()
{
    list <spisok> List;
    string num_group;
    string surname;
    cout << "Input students. If you want to stop entering, please write '.' as number of group and surname\n";
    while (surname != "." and num_group != ".")
    {
        cout << "Number of group: ";
        cin >> num_group;
        cout << "Second name: ";
        cin >> surname;
        spisok lst = {num_group, surname};
        List.push_back(lst);
    }
    List.pop_back();
    string n;
    cout << "Number of group for search: ";
    cin >> n;
    cout << "\nSecond names of students:\n";
    for (auto i : List)
    {
        if (i.num_group == n)
            cout << i.surname << endl;
    }
}

