#include <iostream>

using namespace std;

//this program is for digit sum, the input is a int, the output is the sum of its each digit
int main()
{
    int n,sum = 0;
    cin>>n;
    while (n){
        sum += n%10;
        n /= 10;
    }
    cout<<sum;
    return 0;
}

