#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Example 1: Checking Digit Strings
bool isDigitString(string str) {
  if (str.length() == 0) return false;
  for (int i = 0; i < str.length(); i++) {
    if (!isdigit(str[i])) return false;
  }
  return true;
}

// Example 2: Equality ignoring cases
bool equalsIgnoreCase(string s1, string s2) {
  if (s1.length() != s2.length()) return false;
  for (int i = 0; i < s1.length(); i++) {
    if (tolower(s1[i]) != tolower(s2[i])) return false;
  }
  return true;
}

// Example 3: convert characters to upper cases
string toUpperCase(string str) {
  string result;
  for (int i = 0; i < str.length(); i++) {
    result += toupper(str[i]);
  }
  return result;
}

int main()
{
    string str1 = "123456";
    string str2 = "Hello, world!";
    string str3 = "hello, World!";

    cout << isDigitString(str1) << endl;
    cout << equalsIgnoreCase(str2, str3) << endl;
    cout << toUpperCase(str2) << endl;

    return 0;
}
