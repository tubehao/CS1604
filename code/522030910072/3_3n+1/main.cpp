#include <iostream>
#include<iomanip>
using namespace std;

//this program is for digit sum
int main()
{
    int n = 0;
    double daoshu, pi_4 = 0;
    cin>>n;
    for (int i = 1;i<=n;i++){
        if (i%2 == 0)  pi_4 = pi_4-1.0/(2.0*i-1.0);
        else pi_4 += 1.0/(2.0*i-1.0);
    }
    cout<<fixed<<setprecision(9)<<pi_4*4;
    return 0;
}

