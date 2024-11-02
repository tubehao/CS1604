#include "nat.h"
#include <iostream>
#include <cassert>
using namespace std;

// Create big integers from ordinary integers
nat from_int(int a)
{
    assert(a >= 0);

    vector<int> v;
    while (a > 0) {
        v.push_back(a%10);
        a = a/10;
    }

    return v;
}

// Compute the value and carry of a + b + c
pair<int, int> add_digits(int a, int b, int c)
{
    int v = a + b + c;
    return pair<int,int>(v%10, v/10);
}

// Addition
nat add(nat a, nat b)
{
    // Make the reversed integer strings have the same length;
    int minlen = min(a.size(), b.size());
    int maxlen = max(a.size(), b.size());
    if (a.size() == minlen)
        a.insert(a.end(), maxlen-minlen, 0);
    if (b.size() == minlen)
        b.insert(b.end(), maxlen-minlen, 0);

    // Perform the addition
    int carry = 0;
    vector<int> result;
    for (int i = 0; i < maxlen; i++) {
        int av = a[i],
            bv = b[i];
        auto v = add_digits(av, bv, carry);
        result.push_back(v.first);
        carry = v.second;
    }
    if (carry != 0)
        result.push_back(carry);

    return result;
}

// Print the big integer
void print_nat(nat b)
{
    for (auto it = b.rbegin(); it != b.rend(); it++)
        cout << *it;
}
