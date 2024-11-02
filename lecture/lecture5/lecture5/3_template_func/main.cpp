#include <iostream>

using namespace std;

template <class T>
T id(T v)
{
    return v;
}

int main()
{
    cout << id(65) << endl;
    cout << id('c') << endl;
    string s = "Hello world!";
    cout << id(s) << endl;

    cout << id<char>(65) << endl;
    return 0;
}
