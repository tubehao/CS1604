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
    return 0;
}

