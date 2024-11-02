#include <iostream>
#include <Stack.h>
using namespace std;

int main()
{
    Stack<char> s;
    cout << s << endl;

    s.push('A');
    s.push('B');
    s.push('C');

    cout << s << endl;
    cout << s.peek() << endl;

    s.pop();
    cout << s << endl;

    s.pop();
    cout << s << endl;

    s.pop();
    // s.pop();
    // s.peek();
    return 0;
}
