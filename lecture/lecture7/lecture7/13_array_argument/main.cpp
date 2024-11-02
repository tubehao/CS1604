#include <iostream>
#include <iomanip>
using namespace std;


void printArray1(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void printArray2(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[5] = {4, 2, 1, 3, 5};

    printArray1(a, 5);
    printArray2(a, 5);

    return 0;
}
