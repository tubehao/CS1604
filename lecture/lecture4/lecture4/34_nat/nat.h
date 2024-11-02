#ifndef nat_H_INCLUDED
#define nat_H_INCLUDED

/* ADT for natural numbers */

#include <string>

// Declare an abstract type for natural numbers
typedef std::string nat;

// Operations for natural numbers
nat from_int(int a);
nat add(nat a, nat b);  // a + b
void print_nat(nat b);     // Print the natural numbers


#endif // nat_H_INCLUDED
