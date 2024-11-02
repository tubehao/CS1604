#include "nat.h"
#include <iostream>
using namespace std;

// Convert a char to a digit
int char_to_digit(char a)
{
    return a - '0';
}

// Convert a digit to a char
char digit_to_char(int a)
{
    return a + '0';
}


// Create natural numbers from ordinary integers
nat from_int(int a)
{
    string s;
    if (a <= 0)
        s = "0";
    else {
        while (a != 0) {
            int h = a%10;
            a = a/10;
            s += digit_to_char(h);
        }
    }
    return s;
}

// Compute the value and carry of a + b + c
void add_digits(int a, int b, int c, int& sv, int& sc)
{
    int v = a + b + c;
    sv = v%10;
    sc = v/10;
}

/* The following code implements add using recursion

static nat add_with_carry(nat a, nat b, int c)
{
    if (a.length() == 0 && b.length() == 0) {
        if (c == 0)
            return "";
        else
            return string(1, digit_to_char(c));
    } else if (a.length() == 0) {
        int sv, sc;
        add_digits(0, char_to_digit(b[0]), c, sv, sc);
        string head(1, digit_to_char(sv));
        string tail = add_with_carry(a, b.substr(1), sc);
        return head + tail;
    } else if (b.length() == 0) {
        int sv, sc;
        add_digits(char_to_digit(a[0]), 0, c, sv, sc);
        string head(1, digit_to_char(sv));
        string tail = add_with_carry(a.substr(1), b, sc);
        return head + tail;
    } else {
        int sv, sc;
        add_digits(char_to_digit(a[0]), char_to_digit(b[0]), c, sv, sc);
        string head(1, digit_to_char(sv));
        string tail = add_with_carry(a.substr(1), b.substr(1), sc);
        return head + tail;
    }
}

nat add(nat a, nat b)
{
    return add_with_carry(a, b, 0);
}
*/

// Addition
nat add(nat a, nat b)
{
    int maxlen = max(a.length(), b.length());

    // Perform the addition
    int carry = 0;
    string result;
    for (int i = 0; i < maxlen; i++) {
        int av, bv;

        // Get the current digit from a
        if (i < a.length())
            av = char_to_digit(a[i]);
        else
            av = 0;
        // Get the current digit from b
        if (i < b.length())
            bv = char_to_digit(b[i]);
        else
            bv = 0;

        int v, c;
        add_digits(av, bv, carry, v, c);
        result += digit_to_char(v);
        carry = c;
    }
    if (carry != 0)
        result += digit_to_char(carry);

    return result;
}

// Reverse of strings
string reverse(string str) {
    string rev;
    for (int i = str.length() - 1; i >= 0; i--) {
        rev += str[i];
    }
    return rev;
}

// Print the natural number
void print_nat(nat b)
{
    cout << reverse(b);
}
