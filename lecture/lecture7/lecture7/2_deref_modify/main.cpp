#include <iostream>

using namespace std;

int a = 10;
int main()
{
    int *p;
    p = &a;
    *p = 3;
    cout << *p << endl;
    cout << a << endl;

    int b = 5;
    p = &b;
    *p = *p + 1;
    cout << *p << endl;
    cout << b << endl;
    return 0;
}
