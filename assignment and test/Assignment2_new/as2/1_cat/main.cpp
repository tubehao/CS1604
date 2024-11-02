#include <iostream>

using namespace std;
long long int num[51];

//用于递归爬树的过程
int cat(long long int n){
    if (n == 1) return 0;
    if (n == 2) return 0;
    if (n == 3) return 0;
    if (num[n-1]==0){
        cat(n-1);
    }
    if (num[n-2]==0){
        cat(n-2);
    }
    if (num[n-3]==0){
        cat(n-3);
    }
    num[n] = num[n-3]+num[n-2]+num[n-1];
    return 0;
}

//计算爬树所需次数
int main()
{
    long long int n;
    cin>>n;
    for (int i = 0;i <51; i++){
        num[i] = 0;
    }
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;
    cat(n);
    cout<<num[n];
    return 0;
}
