#include <iostream>
#include <Vector.h>
using namespace std;

void bubble_sort(Vector<int>& vec)
{
    for (int k = 0; k < vec.size()-1; k++) {
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] > vec[i+1])
                swap(vec[i], vec[i+1]);
        }
    }
}

int main()
{
    //Vector<int> vec = {42, -13, 101, -99, 42, 0, 9};
    Vector<int> vec = {101, 42, 42, 9, 0, -13, -99};
    bubble_sort(vec);
    cout << vec << endl;

    return 0;
}
