#include <iostream>
#include "MyMath.h"
using namespace std;

int main()
{
    float x;
    cin>>x;
    int n;
    n = Round(x);
    cout<<"The square root is:"<<MySqrt(x)<<endl;
    cout<<"Its nearest interger is:"<<n<<endl;
    cout<<"Whether the interger is a prime number:"<<prime(n);
    return 0;
}
