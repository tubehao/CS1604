#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++)
            cout << setw(4) << a[i][j] << " ";
        cout << endl;
    }

    cout << a[0][2] << endl;
    cout << a[3][2] << endl;

    return 0;
}
