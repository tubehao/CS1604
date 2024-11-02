#include <iostream>

using namespace std;

int sum(int n)
{
    int s;
    if (n == 0)
        s = 0;
    else
        s = n + sum(n-1);
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
