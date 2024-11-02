#include <iostream>

using namespace std;

// increase the value
int& incr(int& x)
{
    int z = x;
    return ++z;
}

int main()
{
   int y = 4;
   incr(y) = 10;
   cout << y << endl;
   return 0;
}
