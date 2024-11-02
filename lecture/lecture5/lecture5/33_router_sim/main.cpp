#include <iostream>
#include <string>
#include <Queue.h>
#include <Vector.h>
#include <Random.h>

#include <chrono>
#include <thread>
using namespace std;

int CLOCK = 0; // Global clock
int GENMSG_TIME = 2; // Ticks needed for generating a message
int ROUTMSG_TIME = 3; // Ticks needed to route a message

// Generate a random letter
char randomLetter()
{
    return char('a'+ randomInteger(0, 25));
}

// Generate a random message
string randomMessage()
{
    int len = randomInteger(1, 10);
    string res;
    // Randomly generate an important message
    if (randomBool())
        res += '!';

    for (int i = 0; i < len; i++)
        res += randomLetter();

    return res;
}

// Generator
bool generateMessage(Queue<string>& ichannel)
{
    if (CLOCK % GENMSG_TIME != 0)
        return false;

    string msg = randomMessage();
    ichannel.enqueue(msg);
    cout << "Generated: " << msg << endl;

    return true;
}

// Check if a message is important
bool isImportant(const string& msg)
{
    return msg.size() !=0 && msg[0] == '!';
}

// Rounter
bool routeMessage(Queue<string>& ichannel,
                   Queue<string>& specialOut, Queue<string>& regularOut)
{
    if (CLOCK % ROUTMSG_TIME != 0)
        return false;

    if (ichannel.isEmpty()) {
        cout << "No incoming message!" << endl;
        return false;
    }

    string s = ichannel.dequeue();
    if (isImportant(s)) {
        specialOut.enqueue(s);
        cout << "Routed \"" << s << "\" to the special channel" << endl;
    } else {
        regularOut.enqueue(s);
        cout << "Routed \"" << s << "\" to the regular channel" << endl;
    }
    return true;
}

// Simulate
void simulate(int n)
{
    Queue<string> ichannel, specialOut, regularOut;

    // i denotes the number of integers already generated
    int numGen = 0;

    // Every loop performs an operation if
    // it is ready
    while (true) {
        CLOCK++;

        cout << "Time (ticks): " << CLOCK << endl;

        // Run the generator
        if (numGen < n && generateMessage(ichannel))
            numGen++;

        // Run the rounter
        routeMessage(ichannel, specialOut, regularOut);

        cout << "---------------------" << endl;

        // All messages has been generated and routed
        if (numGen == n && ichannel.isEmpty())
            break;

        // Wait for 1 second;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "Outgoing regular messages: " << regularOut << endl;
    cout << "Outgoing special messages: " << specialOut << endl;
}


int main()
{
    int n = 10;
    simulate(10);

    return 0;
}
