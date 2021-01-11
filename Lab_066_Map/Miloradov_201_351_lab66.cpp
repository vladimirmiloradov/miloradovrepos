#include <iostream>
#include <list>
#include <string>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::list;
using std::endl;
using std::map;

struct words
{
    string word_in_text;
};

int main()
{
    map <string, int> mp;
    list <words> text;
    string word;
    cout << "Input text with dot at end:\n";
    while (word != ".")
    {
        cin >> word;
        if ((word != ",") && (word != "!") && (word != "?") && (word != ":") && (word != ";") && (word != "-")) {
            words wrd = { word };
            text.push_back(wrd);
        }
    }
    text.pop_back();
    int k;
    int sz = text.size();
    for (auto i : text)
    {
        k = 0;
        for (auto j : text)
            if (i.word_in_text == j.word_in_text)
                k++;
        mp[i.word_in_text] = k * 100 / sz;
    }
    cout << "Frequency of mention: " << endl;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        cout << (*it).first << " : " << (*it).second << "%" << endl;
    }
}
