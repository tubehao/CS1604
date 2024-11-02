#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <ctime>

//
// Request for encryption of an integer
//
int request(int i);

//
// Callback function for logging feedbacks
// from the encryption server.
// The original value, the encrypted value and
// the time of encryption are logged.
//
void log(int i, int r, std::time_t time);

#endif // CLIENT_H_INCLUDED
