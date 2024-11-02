#include <iostream>

using namespace std;

bool is_odd(unsigned int n);

bool is_even(unsigned int n)
{
    if (n == 0)
        return true;
    else
        return is_odd(n-1);
}

bool is_odd(unsigned int n)
{
    return !is_even(n);
}

int main()
{
    unsigned int n;
    cin >> n;
    if (is_even(n))
        cout << n << " is even!" << endl;
    else
        cout << n << " is odd!" <<endl;

    return 0;
}
