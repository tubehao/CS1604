#include <iostream>
#include <string>
#include <Stack.h>
using namespace std;

// Check if a left symbol
bool isLeftSymbol(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}

// Check if a right symbol
bool isRightSymbol(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}

// Check if brackets are matching
bool isMatching(char left, char right)
{
    return (left == '(' && right == ')') ||
            (left == '[' && right == ']') ||
            (left == '{' && right == '}');
}

// Check the parentheses and brackets
bool isBalanced(const string& str)
{
    Stack<char> pstack;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        // Push left symbols on to the stack
        if (isLeftSymbol(ch))
            pstack.push(ch);
        // Do checking for right symbols
        else if (isRightSymbol(ch)) {
            // Return if no matching left symbol
            if (pstack.isEmpty())
                return false;
            // Pop the paring left symbol and check
            else {
                char left = pstack.pop();
                if (!isMatching(left, ch))
                    return false;
            }
        }
    }

    // Check if all the left symbol has been matched
    return pstack.isEmpty();
}

// Check and print balanced strings
void checkAndPrint(const string& str)
{
    if (isBalanced(str))
        cout << "\"" << str << "\" is blanaced!" << endl;
    else
        cout << "\"" << str << "\" is NOT blanaced!" << endl;
}

int main()
{
    string test1 = "(This [is { a valid } [ test case] ])";
    string test2 = "(This {is [not] (a valid) ] test case)";
    string test3 = "(This (is [not] (a valid) ) test case))";

    checkAndPrint(test1);
    checkAndPrint(test2);
    checkAndPrint(test3);

    return 0;
}
