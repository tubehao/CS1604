#include <iostream>
#include <Set.h>
#include <Vector.h>
using namespace std;

void elimDup(Vector<int>& vec)
{
    Set<int> s;
    for (int v : vec)
        s.add(v);

    vec.clear();
    for (int v : s)
        vec.add(v);
}

int main()
{
    Vector<int> vec = {1, 2, 1, 3, 5, 3, 5, 9, 100, 200, 100};

    elimDup(vec);

    cout << vec << endl;
    return 0;
}
