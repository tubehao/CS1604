#include <iostream>

using namespace std;

int main()
{
    int a = 2, b = 3;  // Scopes of a and b begin
    cout << a << b << endl;
    {
        int a = 4;       // Overwrite the scope of 1st a
        cout << a << b << endl;
    }
    cout << a << b << endl;

    return 0;
}
