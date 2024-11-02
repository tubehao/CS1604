#include <iostream>

using namespace std;

void hanoi(int n, char src, char tgt, char aux)
{
    if (n <= 0) return;

    if (n == 1)
        cout << src << " -> " << tgt << endl;
    else {
        hanoi(n-1, src, aux, tgt);
        cout << src << " -> " << tgt << endl;
        hanoi(n-1, aux, tgt, src);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
