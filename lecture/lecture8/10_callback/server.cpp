#include <chrono>
#include "server.h"
using namespace std::chrono;
//
// Encryption and logging
//
int encrypt(int i, logging_fun f)
{
    int r = (i + 42) * 3 + 1;

    f(i, r, system_clock::to_time_t(system_clock::now()));

    return i;
}
