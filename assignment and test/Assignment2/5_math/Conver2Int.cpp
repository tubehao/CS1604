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

