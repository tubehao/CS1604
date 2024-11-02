#include <iostream>
#include <iomanip>
using namespace std;

// Compute x^y
int power(int x, unsigned int y)
{
    int res = 1;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}

int main()
{
    int n = 16;

    for (int i = 0; i < n; i++)
        cout << right << setw(2) << i
             << setw(8) << power(2, i) << endl;
    return 0;
}
