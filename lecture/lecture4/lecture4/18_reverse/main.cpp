#include <iostream>
#include <string>
using namespace std;

// Reverse of strings
string reverse(string str) {
    string rev;
    for (int i = str.length() - 1; i >= 0; i--) {
        rev += str[i];
    }
    return rev;
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverse(s) << endl;
    return 0;
}
