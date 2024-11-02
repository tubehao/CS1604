#include <iostream>
#include <Vector.h>
using namespace std;

int main()
{
    Vector<int> vec;
    cout << vec.toString() <<endl;

    vec.add(34);
    vec.add(6);
    vec.add(101);

    cout << vec.toString() <<endl;

    vec.add(-99);

    cout << vec.toString() <<endl;

    vec.insert(2, 15);

    cout << vec.toString() << endl;

    vec.remove(2);

    cout << vec.toString() << endl;

    cout << vec.get(2) << endl;

    vec.set(2, -13);
    cout << vec.toString() <<endl;

    Vector<int> vec1 = {34, 6, 101, -99};
    Vector<int> vec2 = {42, 0, 9};

    cout << vec1 + vec2 << endl;
    return 0;
}
