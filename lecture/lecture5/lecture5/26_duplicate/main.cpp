#include <iostream>
#include <Stack.h>
using namespace std;

void duplicate(Stack<int>& s)
{
    if (s.isEmpty()) return;

    int v = s.pop();
    duplicate(s);
    s.push(v);
    s.push(v);
}

int main()
{
    Stack<int> s = {1, 2, 3, 4};
    duplicate(s);
    cout << s << endl;
    return 0;
}
