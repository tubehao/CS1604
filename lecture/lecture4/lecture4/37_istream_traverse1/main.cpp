#include <iostream>

using namespace std;

void read_input(istream& is)
{
    char ch;
    while (is.get(ch)) {
        cout << ch;
    }
}

int main()
{
    read_input(cin);
    return 0;
}
