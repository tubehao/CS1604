#include <iostream>

using namespace std;

const int a = 10;

int main()
{
    const int *p = &a;
    cout << *p << endl;
    // Error
    // *p = 11;

    const int b = 5;
    // p itself is modifiable
    p = &b;
    cout << *p << endl;
    return 0;
}
