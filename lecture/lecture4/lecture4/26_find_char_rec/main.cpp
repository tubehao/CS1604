#include <iostream>
#include <string>
using namespace std;

// Example: Find the character c in the string s
bool find_char(string s, char c)
{
    if (s.length() == 0)
        return false;
    else {
        if (s[0] == c)
            return true;
        else
            return find_char(s.substr(1), c);
    }
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
