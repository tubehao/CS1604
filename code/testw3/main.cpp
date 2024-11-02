#include <iostream>

using namespace std;
int x = 2; int y = 3;
const double PI = 3.14159;
double area(double r) { return PI*r*r; }
int main()
{
  cout << x << "*"<< y << "=" << x*y << endl;
  cout << "PI*" << x << "^2 = " << area(x) << endl;
  return 0;
}

