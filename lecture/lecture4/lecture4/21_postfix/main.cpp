#include <iostream>
#include <string>
using namespace std;

// Example: Check prefixes of strings
bool endsWith(string str, string postfix) {
  if (str.length() < postfix.length())
    return false;

  for (int i = postfix.length()-1; i >= 0; i--) {
    if (str[i+str.length()-postfix.length()] != postfix[i])
      return false;    // Early return
  }
  return true;
}

int main()
{
    string s = "Hello world!";
    string pf;
    getline(cin, pf);
    if (endsWith(s, pf))
        cout << pf << " is a postfix!";
    else
        cout << pf << " is not a postfix!";

    return 0;
}
