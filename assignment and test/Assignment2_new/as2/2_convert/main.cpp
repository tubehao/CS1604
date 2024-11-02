#include <iostream>

using namespace std;

//用于实现tuncate
int Turncate(float x){
    return int(x);
}

//用于实现round
int Round(float x){
    if (x>=0){
        return int(x+0.5);
    }
    else{
        return int(x-0.5);
    }
}

//用于实现largerabs
int LargerAbs(float x){
    if (x<=0){
        return int(x)-1;
    }
    else{
        return int(x)+1;
    }
}

//用于取整
int main()
{
    char tp,bl;
    float x;
    cin>>tp>>x;
    switch(tp){
        case 't':
            cout<<Turncate(x);
            break;
        case 'r':
            cout<<Round(x);
            break;
        case 'l':
            cout<<LargerAbs(x);
            break;
        default:cout<<'Wrong Command';
    }
    return 0;
}
