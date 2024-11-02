#include <iostream>

using namespace std;

int fib(int n)
{
  int fn_1 = 0, fn_2 = 1;
  if (n == 0) return 0;
  if (n == 1) return 1;
  for (int i = 2; i<=n; ++i) {
    int fn = fn_1 + fn_2;
    fn_1 = fn_2;
    fn_2 = fn;
  }
  return fn_2;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
