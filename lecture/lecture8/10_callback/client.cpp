#include <iostream>
#include "client.h"
#include "server.h"
using namespace std;

//
// Request for encryption of an integer
//
int request(int i)
{
    return encrypt(i, log);
}

//
// The logging function
//
void log(int i, int r, time_t time)
{
    cout << "Original value is: " << i << "\n"
        << "Encrypted value is: " << r << "\n"
        << "Encrypted at time: " << std::ctime(&time) << endl;
}
