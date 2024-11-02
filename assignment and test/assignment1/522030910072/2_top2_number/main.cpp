#include <iostream>

using namespace std;

//this program is for big number£¬the input is end while the input is 0,th output is the top 2 large nnumber
int main()
{
    int m1=-100000001,m2=-100000001,n=1;
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


