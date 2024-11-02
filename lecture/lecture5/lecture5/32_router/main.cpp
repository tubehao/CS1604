#include <iostream>
#include <string>
#include <Queue.h>
#include <Vector.h>
#include <Random.h>
using namespace std;

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
void generateMessages(int n, Queue<string>& ichannel)
{
    for (int i = 0; i < n; i++)
        ichannel.enqueue(randomMessage());
}

// Check if a message is important
bool isImportant(const string& msg)
{
    return msg.size() !=0 && msg[0] == '!';
}

// Rounter
void routeMessages(Queue<string>& ichannel,
                   Queue<string>& specialOut, Queue<string>& regularOut)
{
    while (!ichannel.isEmpty()) {
        string s = ichannel.dequeue();
        if (isImportant(s))
            specialOut.enqueue(s);
        else
            regularOut.enqueue(s);
    }
}


int main()
{
    int n = 10;
    Queue<string> ichannel, specialOut, regularOut;
    generateMessages(n, ichannel);
    cout << "Incoming messages: " << ichannel << endl;
    routeMessages(ichannel, specialOut, regularOut);
    cout << "Outgoing regular messages: " << regularOut << endl;
    cout << "Outgoing special messages: " << specialOut << endl;

    return 0;
}
