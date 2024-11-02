#include <iostream>

using namespace std;

/*
int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}*/

// Fibonacci Numbers by Tail-Recursion
int tfib(int n, int fn_1, int fn_2)
{
  if (n == 0) return fn_1;
  if (n == 1) return fn_2;

  return tfib(n-1, fn_2, fn_1+fn_2);
}

int fib(int n)
{
   return tfib(n, 0, 1);
}


int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
