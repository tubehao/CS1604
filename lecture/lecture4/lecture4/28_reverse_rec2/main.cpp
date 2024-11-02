#include <iostream>
#include <string>
using namespace std;

// Reverse of strings
string reverse(string str) {
    if (str.length() <= 1) {
        return str;
    } else {
        int i = str.length()/2;
        string s1 = str.substr(0, i);
        string s2 = str.substr(i);
        return reverse(s2) + reverse(s1);
    }
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverse(s) << endl;
    return 0;
}
