#include <iostream>

using namespace std;

struct Point {
    Point(int px, int py)
      : x(px), y(py) {}

    int x;
    int y;
};


int main()
{
    Point p(3, 5);
    int a = 10;
    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(p.x) << endl;
    cout << sizeof(p.y) << endl;
    return 0;
}
