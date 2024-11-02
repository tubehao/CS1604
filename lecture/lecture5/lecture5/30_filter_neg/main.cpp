#include <iostream>
#include <Random.h>
#include <Queue.h>
#include <Vector.h>
using namespace std;

Vector<int> filterNegInts(Queue<int>& q)
{
    Vector<int> result;

    while (!q.isEmpty()) {
        int v = q.dequeue();
        if (v >= 0)
            result.add(v);
    }

    return result;
}

void generateIntegers(int n, Queue<int>& q)
{
    for (int i = 0; i < n; i++)
        q.enqueue(randomInteger(-100, 100));
}


int main()
{
    int n = 20;
    Queue<int> q;
    generateIntegers(n, q);
    cout << "The original values are: " << q << endl;

    Vector<int> filtered = filterNegInts(q);
    cout << "The filtered values are: " << filtered;

    return 0;
}
