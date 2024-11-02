#include <iostream>
#include <iomanip>
using namespace std;

float dv = 0;//dv = x/g
float acc = 0.1,eps,x,g = 0;
//”√”⁄µ›πÈº∆À„
float MySqrt(float g){
    dv = x/acc;
    g = (g+dv)/2;
    if ((g-acc)<=eps && (acc-g)<=eps) return g;
    acc = g;
    MySqrt(g);
}

