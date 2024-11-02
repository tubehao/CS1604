#include <iostream>
#include <string>
using namespace std;

// Remove all occurrence of r from str
string removeWord(string str, string r)
{
    int l = r.length();
    string res;
    size_t st = 0, ed = str.find(r);
    while (ed != string::npos) {
        res += str.substr(st, ed-st);//加上st ed之间的格
        st = ed+l;
        ed = str.find(r, st);
    }
    res += str.substr(st);

    return res;
}

int main()
{
    string s1 = "A big dog is chasing a big cat";
    string s2 = "big";
    cout << removeWord(s1, s2) << endl;

    return 0;
}
