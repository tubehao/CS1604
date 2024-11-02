#include <iostream>

using namespace std;

int a = 10;
int main() {
    int& b = a;
    int *p = &b;
    *p = 3;
    cout << *p << endl;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
