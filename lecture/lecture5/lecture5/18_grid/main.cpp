#include <iostream>
#include <Grid.h>
using namespace std;

int main()
{
    Grid<int> emptyGrd;
    Grid<int> NonemptyGrd(3, 4);
    cout << emptyGrd << endl;
    cout << NonemptyGrd << endl;

    cout << NonemptyGrd.numRows() << endl;
    cout << NonemptyGrd.numCols() << endl;

    cout << emptyGrd.inBounds(2, 1) << endl;
    cout << NonemptyGrd.inBounds(2, 1) << endl;

    NonemptyGrd.set(2, 1, 5);
    cout << NonemptyGrd.get(2,1) << endl;
    NonemptyGrd[2][1] = 19;
    cout << NonemptyGrd[2][1] << endl;
    return 0;
}
