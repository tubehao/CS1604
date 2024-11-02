#include <iostream>

using namespace std;

// Compute n!
int factorial(int n)
{
   int s=1;

   if (n < 0)
     return -1;

   for (int i = 1; i <= n; ++i)
        s *= i;
   return s;
}

int main()
{
    int n, result;
    cin >> n;

    result = factorial(n);
    if (result < 0)
        cout << "Error!" << endl;
    else
        cout << n << "! = " << factorial(n) << endl;
    return 0;
}
