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
        n = str.find(r,n);
    }

    return str;
}

// Merge characters
string mergeCharacters(string str, char ch)
{
    if (str.length() == 0)
        return str;

    string str1;
    str1 += str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i-1])
            str1 += str[i];
    }
    return str1;
}

// Merge spaces
string mergeSpaces(string str)
{
    return mergeCharacters(str, ' ');
}

int main()
{
    string s1 = "A big dog is chasing a big cat";
    string s2 = "big";
    cout << removeWord(s1, s2) << endl;
    //cout << mergeSpaces(removeWord(s1, s2)) << endl;
    return 0;
}
