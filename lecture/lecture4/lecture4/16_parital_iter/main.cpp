#include <iostream>
#include <string>
using namespace std;

bool startsWith(string str, string prefix) {
  if (str.length() < prefix.length())
    return false;

  for (int i = 0; i < prefix.length(); i++) {
    if (str[i] != prefix[i])
      return false;    // Early return
  }
  return true;
}

int main()
{
    string str = "Hello, world!";
    string s1;
    cin >> s1;
    if (startsWith(str, s1))
        cout << s1 << " is a prefix!";
    else
        cout << s1 << " is not a prefix!";

    return 0;
}
