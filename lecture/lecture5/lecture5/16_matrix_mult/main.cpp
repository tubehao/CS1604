#include <iostream>
#include <Vector.h>
#include <iomanip>
#include <cassert>
using namespace std;

typedef Vector<Vector<int>> Matrix;

// Multiplication of Vector
int multVec(const Vector<int>& v1, const Vector<int>& v2)
{
    assert (v1.size() == v2.size());

    int result = 0;
    for (int i = 0; i < v1.size(); i++)
        result += (v1[i]*v2[i]);

    return result;
}

// Get column
Vector<int> getColumn(const Matrix& m, int i)
{
    Vector<int> vec;
    for (int k = 0; k < m.size(); k++)
        vec.add(m[k][i]);

    return vec;
}

// Multiplication of vector and matrix
Vector<int> multVecMatrix(const Vector<int>& vec, const Matrix& m)
{
    Vector<int> result;
    for (int i = 0; i < m[0].size(); i++) {
        Vector<int> col = getColumn(m, i);
        result.add(multVec(vec, col));
    }

    return result;
}

// Multiplication of matrix
Matrix multMatrix(const Matrix& m1, const Matrix& m2)
{
    assert(m1[0].size() == m2.size());

    Matrix result;
    for (int i = 0; i < m1.size(); i++) {
        Vector<int> row = multVecMatrix(m1[i], m2);
        result.add(row);
    }

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
    Vector<Vector<int>> m1 = { {42, -13, 101, 9},
                                    {10, -99, 62, 0},
                                    {-80, 33, 28, 12} };
    Vector<Vector<int>> m2 = { {1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9},
                                    {10, 11, 12} };


    Matrix m3 = multMatrix(m1, m2);

    printMatrix(m3);

    return 0;
}
