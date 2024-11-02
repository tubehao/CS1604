#include <iostream>

using namespace std;

// Compare and return
// the max value
int max(int a, int b)
{
   if (a > b)
     return a;
   else
     return b;
}


int main()
{
    cout << max(4,2) << endl;
    return 0;
}
