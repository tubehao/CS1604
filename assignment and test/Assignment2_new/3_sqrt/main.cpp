#include<iostream>
#include<iomanip>
using namespace std;

//recursion
float MySqrt(float g, float x, float eps)
{
	float g1 = (g+x/g)/2;
	if((g1-g) <= eps && (g-g1) <= eps) return g1;
	return MySqrt(g1, x, eps);
}
//在精度eps下求x的平方根
int main()
{
	float x, eps;
	cin>>x>>eps;
	cout<<fixed<<setprecision(3)<<MySqrt(x/2, x, eps)<<endl;
	return 0;
}
