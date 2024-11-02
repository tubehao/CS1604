#include <iostream>
#include "client.h"
using namespace std;

//
// Main
//
int main()
{
    int n;

    cout << "Enter the value to be encrypted: ";
    cin >> n;

    return request(n);
}
