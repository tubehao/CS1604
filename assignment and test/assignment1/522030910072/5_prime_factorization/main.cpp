#include <iostream>

using namespace std;

//this program is for prime number, the input is a integer, and the output is the prime yinzi of it
int main()
{
    int n;
    cin>>n;
    for (int i =2;i<=n;i++){
            while (n%i == 0){
                n /= i;
                cout<<i<<" ";
            }
    }
    return 0;
}
