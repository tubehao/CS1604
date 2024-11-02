#include <iostream>
#include <Vector.h>
using namespace std;

Vector<int> removeNegValues(Vector<int> vec)
{
    for (int i = vec.size()-1; i >= 0; i--) {
        if (vec[i] < 0)
            vec.remove(i);
    }
    return vec;
}

int main()
{
    Vector<int> vec = {34, -13, 101, -99, 42, 0, 9};
    Vector<int> vec1 = removeNegValues(vec);
    cout << vec1 << endl;
    return 0;
}
