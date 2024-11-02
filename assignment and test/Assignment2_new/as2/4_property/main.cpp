#include <iostream>
#include "NumberProperty.h"
using namespace std;
//judge if the number is prime and perfect number
int main()
{
    int a;
    cin>>a;
    if (a == 0 || a == 1){
        cout<<0<<" "<<0;
    }
    else{
        cout<<perfect(a)<<" "<<prime(a);
    }

    return 0;
}
