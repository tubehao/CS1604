#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "Hello, world!";
    //s.erase(5,2);
    //s.insert(6, "the beautiful");
    s.replace(7,5, "friend");
    cout << s << endl;
    return 0;
}
