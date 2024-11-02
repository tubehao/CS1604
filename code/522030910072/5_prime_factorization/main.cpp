#include <iostream>

using namespace std;

//this program is for digit sum
int main()
{
    int n;
    cin>>n;
    const int N = n;
    int yinshu[N+1];

    for (int i =1;i<=n;i++){
        if (n%i==0){
            yinshu[i] = 1;
        }
    }
    while (true){
        for (int i =2;i<=n;i++){
            if (yinshu[i] == 1){
                while (n%i == 0){
                    n /= i;
                    cout<<i<<' ';
                    if (n/yinshu[i]==1)
                        break;
                }
            }
        }
    }
    return 0;
}
