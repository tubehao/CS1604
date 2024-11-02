#include <iostream>
#include <string>
using namespace std;

int main()
{
    // String concatenation
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    line1 += line2;
    cout << line1 << endl;

    return 0;
}
