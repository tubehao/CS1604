#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Character selection
    string s = "hello, world";
    int i;
    char c;
    cin >> i >> c;
    s[i] = c;
    cout << "The new string is \"" << s << "\"" << endl;
    return 0;
}
