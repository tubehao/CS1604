#include <iostream>
#include <Stack.h>
using namespace std;

// The original solution
void hanoi(Stack<int> disks, char src, char tgt, char aux)
{
    int n = disks.size();
    if (n <= 0) return;
    if (n == 1)
        cout << disks.peek() << ": " << src << " -> " << tgt << endl;
    else {
        int d = disks.pop();
        hanoi(disks, src, aux, tgt);  // Move n-1 disks
        cout << d << ": " << src << " -> " << tgt << endl;
        hanoi(disks, aux, tgt, src);  // Move n-1 disks
    }
}

int main()
{
    Stack<int> disks = {1, 2, 3, 4, 5};
    hanoi(disks, 'A', 'B', 'C');
    return 0;
}
