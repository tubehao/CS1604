#ifndef NAT_H_INCLUDED
#define NAT_H_INCLUDED

/* ADT for natural numbers */

#include <vector>

// Declare an abstract type for natural numbers
typedef std::vector<int> nat;

// Operations for natural numbers
nat from_int(int a);
nat add(nat a, nat b);  // a + b
void print_nat(nat b);     // Print the natural numbers

#endif // NAT_H_INCLUDED
