#include <iostream>
#include <Vector.h>
#include <iomanip>
#include <cassert>
using namespace std;

typedef Vector<Vector<int>> Matrix;

// Addition of Vector
Vector<int> addVec(const Vector<int>& v1, const Vector<int>& v2)
{
    assert (v1.size() == v2.size());

    Vector<int> vec;
    for (int i = 0; i < v1.size(); i++)
        vec.add(v1[i]+v2[i]);

    return vec;
}

// Addition of matrix
Matrix addMatrix(const Matrix& m1, const Matrix& m2)
{
    assert(m1.size() == m2.size()
           && m1[0].size() == m2[0].size());

    Matrix result;
    for (int i = 0; i < m1.size(); i++)
        result.add(addVec(m1[i], m2[i]));

    return result;
}

void printMatrix(const Matrix& m)
{
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << setw(3) << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Vector<Vector<int>> m1 = { {42, -13, 101},
                                    {10, -99, 62},
                                    {-80, 33, 28},
                                    {9, 0, 12} };

    Vector<Vector<int>> m2 = { {1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9},
                                    {10, 11, 12} };


    Matrix m3 = addMatrix(m1, m2);

    printMatrix(m3);

    return 0;
}
