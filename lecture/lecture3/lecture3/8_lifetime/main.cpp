#include <iostream>

using namespace std;

double g(double t)
{
   return t*2.0;
}

int f(int a, int b)
{
  int c = a + b;
  g(c);
  return c;
}

int x = 2, y = 3;
const double PI = 3.14159;

int main()
{
    f(x, y);
    g(PI);
    return 0;
}
