#include <iostream>
#include <string>
using namespace std;

// Remove all occurrence of r from str
string removeWord(string str, string r)
{
    int l = r.length();
    size_t n = str.find(r);
    while (n != string::npos) {
        str.erase(n, l);
        n = str.find(r, n);
    }

    return str;
}

int main()
{
    string s1 = "A big dog is chasing a big cat";
    string s2 = "big";
    cout << removeWord(s1, s2) << endl;

    return 0;
}
