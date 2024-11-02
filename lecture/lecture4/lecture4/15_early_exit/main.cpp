#include <iostream>

using namespace std;

bool find_char(string s, char c)
{
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

int main()
{
    string str = "Hello world!";
    char c;
    cin >> c;
    if (find_char(str,c))
        cout << c << " is found!" << endl;
    else
        cout << c << " is not found." << endl;
    return 0;
}
