#include <iostream>
#include <string>
#include <Stack.h>
using namespace std;

// Reverse a string
string reverseString(const string& str)
{
    Stack<char> rev;
    for (int i = 0; i < str.length(); i++)
        rev.push(str[i]);

    string result;
    while (!rev.isEmpty()) {
        char ch = rev.pop();
        result += ch;
    }

    return result;
}

int main()
{
    cout << reverseString("Hello world!") << endl;
    return 0;
}
