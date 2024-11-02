#include <iostream>
#include<iomanip>
using namespace std;

//this program is for 3n+1, the input is an integer the output is the times it need to become 1 after certain steps
int main()
{
    int n,sum = 0;
    cin>>n;
    while(n!=1){
        if (n%2 == 0) n /= 2;
        else n = 3*n+1;
        sum++;
    }
    cout<<sum;
    return 0;
}

