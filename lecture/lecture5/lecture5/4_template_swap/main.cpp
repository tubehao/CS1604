#include <iostream>

using namespace std;

template <class T>
void swap_val(T& t1, T& t2)
{
    T temp;
    temp = t1;
    t1 = t2;
    t2 = temp;
}

int main()
{
    int x = 3, y = 5;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swap_val(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    cout << endl;

    string s1 = "Red", s2 = "Blue";
    cout << "Before swapping: s1 = " << s1 << ", s2 = " << s2 << endl;
    swap_val(s1, s2);
    cout << "After swapping: s1 = " << s1 << ", s2 = " << s2 << endl;
    return 0;
}
