#include <iostream>
#include <string>
#include <Vector.h>
using namespace std;

// Concatenate the elements in strs (separated by a single space)
// and return the result
string concatStrings(Vector<string> words)
{
    string result;

    // Fill in the code here

    return result;
}

int main()
{
    Vector<string> words = { "Give", "a", "man", "a", "fish", "and", "you",
                        "feed", "him", "for", "a", "day;", "teach",
                        "a", "man", "to", "fish", "and", "you",
                        "feed", "him", "for", "a", "lifetime." };
    cout << concatStrings(words) << endl;
    return 0;
}
