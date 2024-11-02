#include <iostream>
#include <cctype>
#include <Stack.h>
using namespace std;

bool calculate(Stack<double>& vstack, char op, double& result)
{
    if (vstack.size() < 2) return false;

    double v2 = vstack.pop();
    double v1 = vstack.pop();

    switch (op) {
    case '+':
        result = v1 + v2;
        break;

    case '-':
        result = v1 - v2;
        break;

    case '*':
        result = v1 * v2;
        break;

    case '/':
        result = v1 / v2;
        break;

    default:
        return false;
    }

    vstack.push(result);
    return true;
}

int main()
{
    Stack<double> vstack;
    string input;
    double result;

    while (true) {
        getline(cin, input);
        if (input == "Quit") break;
        if (input == "Print") {
            cout << vstack << endl;
            continue;
        }

        if (isdigit(input[0]))
            vstack.push(atof(input.c_str()));
        else if (calculate(vstack, input[0], result))
            cout << result << endl;
        else {
            cout << "Error encountered!" << endl;
            return -1;
        }
    }
    return 0;
}
