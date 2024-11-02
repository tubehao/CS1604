#include <iostream>
#include <Queue.h>
using namespace std;


int main()
{
    // Initialize an empty queue
    Queue<int> q;
    cout << q << endl;
    // Add values
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q << endl;
    // Print the head element
    cout << q.peek() << endl;
    // Remove the head element
    q.dequeue();
    cout << q << endl;
    // More dequeues
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    // Errors: dequeuing and peeking empty queues
    q.dequeue();
    q.peek();

    return 0;
}
