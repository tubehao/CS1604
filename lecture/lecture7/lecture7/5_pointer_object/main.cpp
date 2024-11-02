#include <iostream>

using namespace std;

// Point structure
struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    Point *pp = &p;
    (*pp).x = 3;
    (*pp).y = 5;
    cout << (*pp).x << (*pp).y;
    return 0;
}
