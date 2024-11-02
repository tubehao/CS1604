#include <iostream>
#include <iomanip>
using namespace std;

float dv = 2;//dv = x/g
float acc,eps = 0.1;
//用于递归计算
float MySqrt(float g,float x){
    g = (g+dv)/2;
    dv = x/g;
    if ((g-acc)<=eps && (acc-g)<=eps) return g;
    acc = g;
    return MySqrt(g,x);

}
