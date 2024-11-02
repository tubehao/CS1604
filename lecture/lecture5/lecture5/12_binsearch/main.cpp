#include <iostream>
#include <Vector.h>
#include <cassert>
using namespace std;


// Recursion
int binary_search_rec(const Vector<int>& vec, int v, int st, int ed)
{
    if (ed < st)
        return -1;

    assert (st >= 0 && st < vec.size() && ed >= 0 && ed < vec.size());

    int mid = (st+ed)/2;
    if (vec[mid] == v)
        return mid;
    else if (v < vec[mid])
        return binary_search_rec(vec, v, st, mid-1);
    else
        return binary_search_rec(vec, v, mid+1, ed);
}

// Binary search
int binary_search(const Vector<int>& vec, int v)
{
    return binary_search_rec(vec, v, 0, vec.size()-1);
}

// Iterative solution
int binary_search_iter(const Vector<int>& vec, int v)
{
    int st = 0, ed = vec.size()-1;
    while (st <= ed) {
        //
    }
    return -1;
}

int main()
{
    Vector<int> vec = {-99, -13, 0, 9, 42, 42, 101};

    int v;
    cin >> v;
    int i = binary_search(vec, v);
    if (i >= 0)
        cout << v << " is found at index " << i << endl;
    else
        cout << v << " is not found";

    return 0;
}
