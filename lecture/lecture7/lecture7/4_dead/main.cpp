#include <iostream>

using namespace std;

// Error: x is dead after return
int* getX() {
    int x;
    return &x;
}

int main() {
    cout << *getX() << endl;
    return 0;
}
