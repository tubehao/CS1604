#include <iostream>

using namespace std;

int average(int x, int y)
{
   int result;
   result = (x + y) / 2;
   return result;
}

int main()
{
    int  a=10,  b=20, ave;
    ave = average(a, b);
    cout << ave << endl;
    return 0;
}
