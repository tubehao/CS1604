#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    if (str.length() <= 1)
        return true;
    else if (str[0] != str[str.length()-1])
        return false;
    else
        return isPalindrome(str.substr(1, str.length()-2));
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
