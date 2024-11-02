#include <iostream>
#include <string>
using namespace std;

void print_nlines(int n, string s)
{
    for (int i = 0; i < n; i++)
        cout << s << endl;
}

int main()
{
    string str;
    int n;
    cin >> str >> n;
    cout << endl;
    print_nlines(n, str);

    return 0;
}
