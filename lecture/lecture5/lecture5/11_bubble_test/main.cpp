#include <iostream>
#include <Vector.h>
#include <cassert>
using namespace std;

bool is_sorted(const Vector<int>& vec, int start)
{
    for (int i = start; i < vec.size()-1; i++)
        if (vec[i] > vec[i+1])
            return false;
    return true;
}

void bubble_sort(Vector<int>& vec)
{
    for (int k = 0; k < vec.size()-1; k++) {
        assert(is_sorted(vec, vec.size()-k-1));
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] > vec[i+1])
                swap(vec[i], vec[i+1]);
        }
    }
    assert(is_sorted(vec, 0));
}

int main()
{
    //Vector<int> vec = {42, -13, 101, -99, 42, 0, 9};
    Vector<int> vec = {101, 42, 42, 9, 0, -13, -99};
    bubble_sort(vec);
    cout << vec << endl;

    return 0;
}
