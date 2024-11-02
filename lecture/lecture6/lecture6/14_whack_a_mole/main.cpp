#include <iostream>
#include <cassert>
#include "engine.h"
using namespace std;

void testField1()
{
    Field f(5);
    assert (f.addMole(0, 0, true));
    assert (f.addMole(1, 2, true));
    assert (f.addMole(2, 3, false));

    f.display(cout);
}

void testField2()
{
    Field f = randomField(6);
    f.display(cout);

    for (int i = 0; i < 10; i++) {
        f.randomize();
        f.display(cout);
    }
}

int main()
{
    // testField2();
    play(cout, 10);
    return 0;
}
