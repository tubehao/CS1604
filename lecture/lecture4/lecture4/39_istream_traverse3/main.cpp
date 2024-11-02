#include <iostream>
#include <string>
using namespace std;

void read_input(istream& is)
{
    string line;
    int count = 0;
    while (getline(is, line)) {
        count++;
        cout << "Line " << count << ": " << line << endl;
    }
}

int main()
{
    read_input(cin);
    return 0;
}
