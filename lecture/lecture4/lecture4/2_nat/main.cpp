#include <iostream>
#include <climits>
#include "nat.h"
using namespace std;

int main()
{
    int a = INT_MAX, b = INT_MAX;
    cout << "INT_MAX is " << INT_MAX << endl;
    cout << "INT_MAX + INT_MAX is " << a + b << endl;

    nat ap = from_int(a), bp = from_int(b);
    cout << "Addition of two natural numbers of value INT_MAX is ";
    print_nat(add(ap, bp));
    cout << endl;

    // Extra test
    cout << "Enter two natural numbers:";
    cin >> a >> b;
    cout << "Print their addition: ";
    print_nat(add(from_int(a), from_int(b)));
    return 0;
}
