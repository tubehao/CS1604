#include <iostream>

using namespace std;

// Point structure
struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    int* py = &p.y;
    *py = 10;
    cout << *py << endl;
    cout << p.y << endl;
    return 0;
}
