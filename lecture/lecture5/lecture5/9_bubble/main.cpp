#include <iostream>
#include <Vector.h>
using namespace std;

bool is_sorted(const Vector<int>& vec)
{
    for (int i = 0; i < vec.size()-1; i++)
        if (vec[i] > vec[i+1])
            return false;
    return true;
}

void bubble_sort(Vector<int>& vec)
{
    while (!is_sorted(vec)) {
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] > vec[i+1]) {
                int temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
            }
        }
    }
}

int main()
{
    Vector<int> vec = {42, -13, 101, -99, 42, 0, 9};
    bubble_sort(vec);
    cout << vec << endl;

    return 0;
}
