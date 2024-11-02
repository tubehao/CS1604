#include <iostream>
#include <Random.h>
#include <Queue.h>
#include <Vector.h>

#include <chrono>
#include <thread>

using namespace std;

int CLOCK = 0; // Global clock
const int FILTER_TIME = 3; // Filter runs every 3 ticks
const int GENINT_TIME = 2; // Generator runs every 2 tick

// Filter
bool filterNegInt(Queue<int>& q, Vector<int>& res)
{
    if (CLOCK % FILTER_TIME != 0)
        return false;

    if (q.isEmpty()) {
        cout << "Nothing to filter" << endl;
        return false;
    }
    else {
        int v = q.dequeue();
        if (v >= 0) {
            res.add(v);
            cout << "Kept: " << v << endl;
        } else
            cout << "Discarded: " << v << endl;
        return true;
    }
}

// Generator
bool generateInteger(Queue<int>& q)
{
    if (CLOCK % GENINT_TIME != 0)
        return false;

    int v = randomInteger(-100, 100);
    cout << "Generated: " << v << endl;
    q.enqueue(v);

    return true;
}

// Simulation loop
// n denotes the number of integers to be generated
void simulate(int n)
{
    Queue<int> q;
    Vector<int> vec;

    // i denotes the number of integers already generated
    int numGen = 0;
    int numFilter = 0;

    // Every loop performs an operation if
    // it is ready
    while (true) {
        CLOCK++;

        cout << "Time (ticks): " << CLOCK << endl;

        // Run the generator
        if (numGen < n && generateInteger(q))
            numGen++;

        // Run the filter
        filterNegInt(q, vec);

        cout << "---------------------" << endl;

        // All numbers has been generated and filtered
        if (numGen == n && q.isEmpty())
            break;

        // Wait for 1 second;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "The final result is: " << vec << endl;
}

int main()
{
    simulate(10);
    return 0;
}
