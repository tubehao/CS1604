#include <iostream>

using namespace std;

int add(int x, int y)
{
    cout << "Running add for integers." << endl;
    return x + y;
}

double add(double x, double y)
{
    cout << "Running add for doubles." << endl;
    return x + y;
}


int main()
{
    cout << add(3, 5) << endl << endl;
    cout << add(1.0, 3.14159) <<endl;
    return 0;
}
