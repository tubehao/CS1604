#include <iostream>

using namespace std;

//this program is for digit sum
int main()
{
    int m1,m2,n=1;
    while (n!=0){
        cin>>n;
        if (n>m1){
            m2 = m1;
            m1 = n;
        }
        else{
            if (n>m2){
                m2 = n;
            }
        }
    }
    cout<<m1<<' '<<m2;
    return 0;
}


