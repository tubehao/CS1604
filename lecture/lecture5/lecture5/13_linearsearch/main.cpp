#include <iostream>
#include <Vector.h>
using namespace std;


// Linear search
int find_element(const Vector<int>& vec, int v)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == v)
            return i;
    return -1;
}

int main()
{
    Vector<int> vec = {42, -13, 101, -99, 42, 0, 9};

    int v;
    cin >> v;
    int i = find_element(vec, v);
    if (i >= 0)
        cout << v << " is found at index " << i << endl;
    else
        cout << v << " is not found";

    return 0;
}
