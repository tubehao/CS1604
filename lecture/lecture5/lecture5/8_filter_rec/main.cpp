#include <iostream>
#include <Vector.h>
using namespace std;

Vector<int> removeNegValues(Vector<int> vec)
{
    if (vec.isEmpty())
        return Vector<int>();
    else {
        Vector<int> head;
        // Keep vec[0] if it is not a negative value
        if (vec[0] >= 0) head.add(vec[0]);
        // Get the rest elements
        vec.remove(0);
        Vector<int> rest = removeNegValues(vec);

        return head + rest;
    }
}

int main()
{
    Vector<int> vec = {34, -13, 101, -99, 42, 0, 9};
    cout << removeNegValues(vec) << endl;
    return 0;
}
