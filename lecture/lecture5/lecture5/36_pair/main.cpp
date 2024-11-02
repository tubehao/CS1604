#include <iostream>

using namespace std;

int main()
{
    pair<string, int> p;
    pair<string, int> p1("abc", 1);
    pair<char, double> p2 = make_pair('C', 2.0);

    cout << "(" << p.first << ", " << p.second << ")" << endl;
    cout << "(" << p1.first << ", " << p1.second << ")" << endl;
    cout << "(" << p2.first << ", " << p2.second << ")" << endl;

    return 0;
}
