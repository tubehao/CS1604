#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a = 10;
    char dst[10];
    char str[] = "beauty is only skin deep";
    strcpy(dst, str);
    cout << a << endl;
    return 0;
}
