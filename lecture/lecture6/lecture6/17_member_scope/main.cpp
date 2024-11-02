#include <iostream>

using namespace std;

int a = 10;

class Foo {
public:
    Foo(int v) : {a = v}

    void print() const {
        cout << a << endl;
    }

private:
    int a;
};

int main()
{
    Foo f(3);
    f.print();

    return 0;
}
