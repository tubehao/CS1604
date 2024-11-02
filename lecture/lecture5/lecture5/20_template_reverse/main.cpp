#include <iostream>
#include <Vector.h>
using namespace std;

Vector<int> reverseVectorInt(const Vector<int>& vec)
{
    Vector<int> result;
    for (int i = vec.size()-1; i >= 0; i--)
        result.add(vec[i]);

    return result;
}

Vector<string> reverseVectorString(const Vector<string>& vec)
{
    Vector<string> result;
    for (int i = vec.size()-1; i >= 0; i--)
        result.add(vec[i]);

    return result;
}

int main()
{
    Vector<int> vec = {42, -13, 101, -99, 42, 0, 9};
    Vector<string> svec = {"Journey", "to", "the", "West"};

    cout << reverseVectorInt(vec) << endl;
    cout << reverseVectorString(svec) << endl;

    return 0;
}
