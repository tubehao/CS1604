#include <iostream>
using namespace std;

//����ʵ��tuncate
int Turncate(float x){
    return int(x);
}

//����ʵ��round
int Round(float x){
    if (x>=0){
        return int(x+0.5);
    }
    else{
        return int(x-0.5);
    }
}

//����ʵ��largerabs
int LargerAbs(float x){
    if (x<=0){
        return int(x)-1;
    }
    else{
        return int(x)+1;
    }
}

