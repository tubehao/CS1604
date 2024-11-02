#include <iostream>
#include <string>
using namespace std;

// Repeat Characters
string repeatChar(int n, char ch) {
    string str;
    for (int i = 0; i < n; i++) {
        str += ch;
    }
    return str;
}

// Repeat Strings
string repeatString(int n, string s) {
    string str;
    for (int i = 0; i < n; i++) {
        str += s;
    }
    return str;
}

int main()
{
    string s;
    char c;
    int n;
    cin >> s >> c >> n;
    cout << repeatChar(n, c) << endl;
    cout << repeatString(n, s) << endl;
    return 0;
}
