#include <iostream>
#include <Vector.h>
#include <Grid.h>
#include <Map.h>
#include <Set.h>
#include <Stack.h>
#include <Queue.h>
using namespace std;

int main()
{
    // Iteration of vectors
    Vector<int> vec = {1, 2, 3, 4, 5};
    for (int v : vec)
        cout << v << " ";
    cout << endl << endl;

    // Iteration of grids
    Grid<double> matrix = { {42, -13, 101},
                            {10, -99, 62},
                            {-80, 33, 28},
                            {9, 0, 12} };
    for (double v : matrix)
        cout << v << " ";
    cout << endl << endl;

    // Iteration of maps
    Map<string, double> m = {{"Cabbage", 11.4}, {"Pork", 17.6}, {"Beef", 20.1}};
    for (string key: m)
        cout << key << ", " << m[key] << endl;
    cout << endl;

    // Iteration of sets
    Set<int> s = {200, 100, 50, 100, 300};

    for (int v : s)
        cout << v << " ";
    cout << endl << endl;

    // No Iteration for Stacks
    Stack<int> stack = {1, 2, 3, 4, 5};
    for (int v : stack)
        cout << v << " ";
    cout << endl << endl;

    return 0;
}
