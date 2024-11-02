#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    int **pp = &p;

    **pp = 5;
    cout << **pp << endl;
    cout << a << endl;

    int b = 7;
    // Switch of address
    p = &b;

    **pp = -10;
    cout << **pp << endl;
    cout << b << endl;

    return 0;
}
