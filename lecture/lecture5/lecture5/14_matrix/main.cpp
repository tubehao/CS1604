#include <iostream>
#include <Vector.h>
#include <iomanip>
using namespace std;

int main()
{
    Vector<Vector<int>> matrix = { {42, -13, 101},
                                    {10, -99, 62},
                                    {-80, 33, 28},
                                    {9, 0, 12} };

    cout << matrix << endl;
    cout << matrix[0] << endl;
    cout << matrix[2] << endl;
    cout << matrix[2][2] << endl;

    cout << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
