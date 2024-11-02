#include "nat.h"
#include <iostream>
#include <cassert>
using namespace std;

// Create big integers from ordinary integers
nat from_int(int a)
{
    assert(a >= 0);

    string s = to_string(a);
    return string(s.rbegin(), s.rend());
}

// Convert a char to a digit
int char_to_digit(char a)
{
    assert ('0' <= a && a <= '9');
    return a - '0';
}

// Convert a digit to a char
char digit_to_char(int a)
{
    assert (0 <= a && a <= 9);
    return a + '0';
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
    int minlen = min(a.length(), b.length());
    int maxlen = max(a.length(), b.length());
    if (a.length() == minlen)
        a += string(maxlen-minlen, '0');
    if (b.length() == minlen)
        b += string(maxlen-minlen, '0');

    // Perform the addition
    int carry = 0;
    string result;
    for (int i = 0; i < maxlen; i++) {
        int av = char_to_digit(a[i]),
            bv = char_to_digit(b[i]);
        auto v = add_digits(av, bv, carry);
        result += digit_to_char(v.first);
        carry = v.second;
    }
    if (carry != 0)
        result += digit_to_char(carry);

    return result;
}

// Print the big integer
void print_nat(nat b)
{
    string s(b.rbegin(), b.rend());
    cout << s;
}
