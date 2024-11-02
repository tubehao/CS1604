#include <iostream>

using namespace std;

// Exponentials
int power(int n, int k)
{
  if (k == 0)
    return 1;
  else
    return n * power(n, k-1);
}

int epower(int n, int k)
{
    if (k == 0)
        return 1;
    else {
        int r = epower(n, k/2);
        r = r*r;
        if (k % 2 == 0)
            return r;
        else
            return r*n;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << epower(n,k) << endl;
    return 0;
}
