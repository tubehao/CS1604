#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    const int N = 5;
    int a[N];

    for (int i = 0; i < N; i++)
        a[i] = rand();

    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    int n = sizeof(a)/sizeof(a[0]);
    assert (n == N);

    cout << *a << endl;
    return 0;
}
