#include <iostream>
#include <Set.h>
using namespace std;

Set<char> getAlphas()
{
    Set<char> s;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        s.add(ch);
        s.add(ch-'a'+'A');
    }
    return s;
}

bool isalpha(char ch)
{
    Set<char> letters = getAlphas();
    return letters.contains(ch);
}

int main()
{
    cout << isalpha('h') << endl;
    cout << isalpha('M') << endl;
    cout << isalpha('!') << endl;

    return 0;
}
