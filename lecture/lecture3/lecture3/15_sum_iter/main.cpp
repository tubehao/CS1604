#include <iostream>

using namespace std;

int tsum(int i, int n, int acc)
{
    if (i > n)
        return acc;

    return tsum(i+1, n, i+acc);
}

int sum(int n)
{
    return tsum(1, n, 0);
}

int main()
{
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
