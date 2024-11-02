#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <ctime>

//
// Prototype for logging functions
//
typedef void (*logging_fun)(int i, int r, std::time_t time);

//
// Encryption and logging
//
int encrypt(int i, logging_fun f);

#endif // SEVER_H_INCLUDED
