#include <iostream>
#include <string>

using namespace std;
int main(){

    string str = "GeeksforGeeks";

    //Use of reverse iterators
    string rev = string(str.rbegin(),str.rend());

    cout<<rev<<endl;
    return 0;
}
