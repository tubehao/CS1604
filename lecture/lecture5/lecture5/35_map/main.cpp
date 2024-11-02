#include <iostream>
#include <string>
#include <Map.h>
using namespace std;

int main()
{
    Map<string, double> m = {{"Cabbage", 11.4}};

    cout << m << endl;

    m.put("Pork", 17.6);
    m.put("Beef", 20.1);

    cout << m << endl;
    cout << m.get("Beef") << endl;
    cout << m.get("Lamb") << endl;

    m.remove("Beef");
    cout << m << endl;

    m.remove("Lamb");
    cout << m << endl;

    cout << m.containsKey("Pork") << endl;
    cout << m.containsKey("Lamb") << endl;
    return 0;
}
