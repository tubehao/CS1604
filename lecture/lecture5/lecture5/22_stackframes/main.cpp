#include <iostream>
#include <Stack.h>
using namespace std;

// Push a pseudo frame for function fname and print a message
void pushAndPrint(Stack<string>& frames, const string& fname)
{
    frames.push(string("Frame ") + fname);
    cout << "Push: " << frames << endl;
}

// Pop a pseudo frame and print a message
void popAndPrint(Stack<string>& frames)
{
    frames.pop();
    cout << "Pop:  " << frames << endl;
}

// Function H
void h(Stack<string>& frames)
{
    pushAndPrint(frames, "H");
    popAndPrint(frames);
}

// Function F
void f(Stack<string>& frames)
{
    pushAndPrint(frames, "F");
    h(frames);
    h(frames);
    popAndPrint(frames);
}

// Function G
void g(Stack<string>& frames)
{
    pushAndPrint(frames, "G");
    popAndPrint(frames);
}

// Function Main
int main()
{
    Stack<string> frames;

    pushAndPrint(frames, "Main");
    f(frames);
    g(frames);
    popAndPrint(frames);
    return 0;
}
