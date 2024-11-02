#include <iostream>

using namespace std;

void read_input(istream& is)
{
    while (true) {
        int ch = is.get();
        if (ch == EOF) break;
        cout << char(ch);
    }
}

void read_input1(istream& is)
{
    int ch;
    while ((ch = is.get()) != EOF) {
        cout << char(ch);
    }
}

int main()
{
    read_input(cin);
    return 0;
}
