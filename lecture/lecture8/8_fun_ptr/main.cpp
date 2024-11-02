#include <iostream>
#include <Random.h>
using namespace std;

//
// Bubble sorting algorithm.
// Given an array, use bubble sorting to sort the elements
// The order of elements after sorting is determined by the last function argument
//
void bubble_sort(int arr[], int num, bool (*cmp)(int, int))
{
    for (int k = 0; k < num - 1; k++)
        for (int i = 0; i < num - 1; i++) {
            if (!cmp(arr[i], arr[i + 1]))
                swap(arr[i], arr[i + 1]);
        }
}

//
// Less than function for integers
//
bool le_int(int a, int b)
{
    return a < b;
}

//
// Greater than function for integers
//
bool ge_int(int a, int b)
{
    return a > b;
}

//
// A random function
//
int foo(int x)
{
    cout << x << endl;
    return x + 1;
}

//
// Main
//
int main()
{
    //
    // Basic examples of function pointers
    //
    int (*p)(int) = foo;

    cout << p(10) << endl;

    //
    // The sorting example
    //
    const int n = 10;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = randomInteger(-100, 100);

    bubble_sort(a, n, ge_int);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
