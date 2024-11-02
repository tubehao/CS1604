#include <iostream>
#include "MyMath.h"
#include <iomanip>
using namespace std;
//the function is based on the problem
int main()
{
    float x;
    cin>>x;
    int n;
    n = Round(MySqrt(x/2,x));
    cout<<"The square root is:"<<fixed<<setprecision(1)<<MySqrt(x/2,x)<<endl;
    cout<<"Its nearest integer is:"<<n<<endl;
    cout<<"Whether the integer is a prime number:"<<prime(n)<<endl;
    return 0;
}
