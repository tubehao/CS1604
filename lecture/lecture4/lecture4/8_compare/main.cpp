#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    cout << "Equal: " << (line1 == line2) << endl;
    cout << "Not equal: " << (line1 != line2) << endl;
    cout << "Less than: " << (line1 < line2) << endl;
    cout << "Less than or equal: " << (line1 <= line2) << endl;
    cout << "Greater than: " << (line1 > line2) << endl;
    cout << "Greater than or equal: " << (line1 >= line2) << endl;

    return 0;
}
