#include <map>
#include <algorithm>
#include <cmath>

const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof values / sizeof (int);

int main()
{
    using namespace std;

    typedef map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++)
        m.insert(make_pair(values[i], pow(values[i], .5)));

    valmap::iterator it = 100;              // error
    valmap::iterator it2(100);              // error
    m.insert(1,2);                          // error

    return 0;
}
