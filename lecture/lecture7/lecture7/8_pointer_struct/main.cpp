#include <iostream>

using namespace std;

struct Line {
    Line(int px1, int py1, int px2, int py2)
        : x1(px1), y1(py1), x2(px2), y2(py2)
    {}
    int x1, y1, x2, y2;
};

int main()
{
    Line line(2, 3, 7, 9);
    int *p = &line.x1;
    cout << *p << endl;
    cout << *(p+1) << endl;
    cout << *(p+2) << endl;
    cout << *(p+3) << endl;
    return 0;
}
