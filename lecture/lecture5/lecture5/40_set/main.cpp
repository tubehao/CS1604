#include <iostream>
#include <Set.h>
using namespace std;

int main()
{
    Set<int> s;
    Set<string> s1 = {"Beef", "Cabbage", "Pork", "Lamb"};

    cout << s << endl;
    cout << s1 << endl;

    s.add(100);
    s.add(200);
    s.add(100);
    s.add(300);

    cout << s << endl;

    s.remove(100);
    cout << s << endl;

    cout << s.contains(100) << endl;
    cout << s.contains(200) << endl;

    Set<string> s2 = {"Beef", "Cabbage", "Beef"};

    cout << s2.isSubsetOf(s1) << endl;
    s2.add("Crab");

    cout << s2 << endl;
    cout << s2.isSubsetOf(s1) << endl;

    cout << s1 + s2 << endl;
    cout << s1 * s2 << endl;
    cout << s1 - s2 << endl;
    return 0;
}
