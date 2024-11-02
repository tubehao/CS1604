#include <iostream>
#include "Random.h"
#include "LinkedList.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    LinkedList* l = NULL;
    for (int i = 0; i < n; i++)
        l = push(l, randomInteger(1, 100));
    print(l);

    // Test copy using iteration
    LinkedList* l1 = copy_iter(l);
    print(l1);
    destroy(l1);

    destroy(l);
    return 0;
}
