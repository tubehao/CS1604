#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Hello, world!";
    cout << s1.find('o') << endl;
    cout << s1.find('o',5) << endl;
    cout << s1.find('x') << endl;
    cout << s1.find("wo") << endl;

    return 0;
}
