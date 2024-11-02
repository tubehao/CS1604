#include <iostream>
using namespace std;
//the same as problem 4
bool prime(int x){
    if (x == 1) return 0;
    for (int i = 2;i<x;i++){
        if (x%i == 0) return 0;
    }
    return 1;
}

bool perfect(int n){
    int sum = 0;
    const int N = n;
    int yinshu[N+1];
    for (int i =1;i<n;i++){
        if (n%i==0){
            sum+=i;
        }
    }
    return (sum == n);
}
