#include <iostream>

using namespace std;

class Counter {
public:
    Counter() : cnt(0) {}
    Counter(int n) : cnt(n) {}

    int get() const { return cnt; }
    void reset() { cnt = 0; }
    void incr() { cnt++; }

private:
    int cnt;
};


int main()
{
    Counter c;
    Counter *p = &c;

    for (int i = 0; i < 10; i++)
        (*p).incr();

    cout << (*p).get() << endl;
    return 0;
}
