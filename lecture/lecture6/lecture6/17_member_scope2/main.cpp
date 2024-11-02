#include <iostream>

using namespace std;

class Foo {
public:
    Foo(int v) : i(v) {}

    void print() const {
        for (int i=0; i < 3; i++)
            cout << i << endl;
    }

private:
    int i;
};

int main()
{
    Foo f(10);
    f.print();

    return 0;
}
