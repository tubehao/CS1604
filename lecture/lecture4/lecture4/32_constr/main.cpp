#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("Hello, world!");
    string s1(10, 'x');
    string s2(s, 7);
    string s3(s, 7,5);
    cout << s << endl
          << s1 << endl
          << s2 << endl
          << s3 << endl;
    return 0;
}
