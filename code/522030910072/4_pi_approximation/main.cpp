#include <iostream>
#include<iomanip>
using namespace std;

//this program is for digit sum
int main()
{
    int n;
    double daoshu,pi,pi_4=0;
    cin>>n;
    for (int i = 1;i<=n;i++){
        daoshu = 1.0/(2.0*i -1.0);
        if (i%2 == 0){
            pi_4 -= daoshu;
        }
        else pi_4 += daoshu;
    }
    pi = pi_4*4;
    cout<<fixed<<setprecision(9)<<pi;
    return 0;
}
