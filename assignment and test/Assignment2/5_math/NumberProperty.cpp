#include <iostream>
using namespace std;
bool prime(int x){
    for (int i = 2;i<x;i++){
        if (x%i == 0) return 0;
    }
    return 1;
}

bool perfect(int n){
    int sto,sum = 1;
    bool eq = 0;
    sto = n;
    const int N = n;
    int yinshu[N+1];

    for (int i =1;i<=n;i++){
        if (n%i==0){
            yinshu[i] = 1;
        }
    }
    for (int i =2;i<=n;i++){
        if (yinshu[i] == 1){
            while (n%i == 0){
                n /= i;
                sum += i;
                if (n/yinshu[i]==1)
                    break;
            }
        }
    }
    return (sum == sto);
}
