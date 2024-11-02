#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-1])
            return false;
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    if (isPalindrome(s))
        cout << "\"" << s << "\" is a palindrome." << endl;
    else
        cout << "\"" << s << "\" is not a palindrome." << endl;

    return 0;
}
