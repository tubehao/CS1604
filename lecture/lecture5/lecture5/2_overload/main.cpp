#include <iostream>

using namespace std;

int add(int x, int y)
{
    cout << "Running add for integers (2-inputs)." << endl;
    return x + y;
}

double add(int x, int y)
{
    cout << "Running add for integers (2-inputs)." << endl;
    return x + y;
}

int add(int x, int y, int z)
{
    cout << "Running add for integers (3-inputs)." << endl;
    return x + y + z;
}


int main()
{
    cout << add(3, 5) << endl << endl;
    cout << add(3, 5, 7) <<endl;
    return 0;
}
