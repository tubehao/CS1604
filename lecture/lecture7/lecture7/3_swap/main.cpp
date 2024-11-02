#include <iostream>

using namespace std;

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 3, y = 5;
    swap(&x, &y);
    cout << x << y << endl;
    return 0;
}
