#include <iostream>
#include <iomanip>
using namespace std;

float dv = 2;//dv = x/g
float acc,eps,x,g = 0;
//���ڵݹ����
float MySqrt(float g){
    g = (g+dv)/2;
    dv = x/g;
    if ((g-acc)<=eps && (acc-g)<=eps) return g;
    acc = g;
    MySqrt(g);
}

//���ƿ���
int main()
{
    cin>>x>>eps;
    cout<<fixed<<setprecision(3)<<MySqrt(x/2);
    return 0;
}
