#include <iostream>

using namespace std;

int main()
{
    int a[5] = {4, 2, 1, 3, 5};
    cout << *(a+2) << endl << endl;
    for (int i = 0; i < 5; i++)
       cout << *(a+i) << endl;

    cout << endl;
    for (int *p = a; p != a+5; p++)
        cout << *p << endl;

    cout << endl;
    int *p = a+5;
    for (int i = 1; i <= 5; i++)
        cout << *(p-i) << endl;
    return 0;
}
