#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;

LinkedList* push(LinkedList* l, int value)
{
    LinkedList* newl = new LinkedList;
    newl->value = value;
    newl->next = l;
    return newl;
}

int peek(LinkedList* l)
{
    if (l == NULL) return 0;
    return l->value;
}

LinkedList* pop(LinkedList* l)
{
    if (l == NULL) return NULL;
    LinkedList* next = l->next;
    delete l;
    return next;
}

void destroy(LinkedList* l)
{
    while (l != NULL)
        l = pop(l);
}

void print(LinkedList* l)
{
    for (LinkedList* p = l; p != NULL; p = p->next)
        cout << p->value << " ";
    cout << endl;
}

LinkedList* copy(LinkedList* l)
{
    if (l == NULL)
        return NULL;

    LinkedList* newl = new LinkedList;
    newl->value = l->value;
    newl->next = copy(l->next);
    return newl;
}

LinkedList* getIth(LinkedList* l, int i)
{
    return getIthPrev(l, i).second;
}

std::pair<LinkedList*, LinkedList*> getIthPrev(LinkedList* l, int i)
{
    assert(i >= 0);
    LinkedList* prev = NULL;
    while (l != NULL && i != 0) {
        prev = l;
        l = l->next;
        i--;
    }

    return make_pair(prev, l);
}
