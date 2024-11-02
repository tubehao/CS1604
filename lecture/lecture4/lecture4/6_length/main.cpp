#include <iostream>
#include <string>
using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    cout << "Length of alphabet: " << ALPHABET.length() << endl;

    string name;
    getline(cin, name);
    cout << "Length of name: " << name.length() << endl;
    return 0;
}
