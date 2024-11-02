#include <iostream>
#include <string>
using namespace std;

void encode_string(string str, int ofs)
{
    if (str.length() == 0)
        return;
    else {
        char c = str[0] + ofs;
        cout << c;
        encode_string(str.substr(1), ofs);
    }
}

int main()
{
    string str = "Hello world!";
    int ofs;
    cin >> ofs;
    encode_string(str, ofs);
    return 0;
}
