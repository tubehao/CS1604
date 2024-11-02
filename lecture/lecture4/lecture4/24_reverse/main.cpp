#include <iostream>
#include <string>
using namespace std;

// Repeat Characters
string repeatChar(int n, char ch) {
    string str;
    for (int i = 0; i < n; i++) {
        str += ch;
    }
    return str;
}

// Reverse the words in a string
string reverseWord(string str)
{
    string res;
    size_t st = 0, ed = str.find(' ');
    while (ed != string::npos) {
        // Prepend a word
        res = str.substr(st, ed-st) + res;
        st = ed;
        // Prepend empty spaces
        while (str[ed] == ' ') ed++;
        res = repeatChar(ed-st, ' ') + res;
        // Search for the next word
        st = ed;
        ed = str.find(' ', st);
    }
    res = str.substr(st) + res;

    return res;
}

int main()
{
    string s1 = "A big dog is chasing a big cat";
    cout << reverseWord(s1) << endl;
    return 0;
}
