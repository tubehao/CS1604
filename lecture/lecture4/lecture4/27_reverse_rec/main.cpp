#include <iostream>
#include <string>
using namespace std;

// Reverse of strings
string reverse(string str) {
    if (str.length() == 0) {
        return "";
    } else {
        string rt = reverse(str.substr(1));
        return rt + str[0];
    }
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverse(s) << endl;
    return 0;
}
