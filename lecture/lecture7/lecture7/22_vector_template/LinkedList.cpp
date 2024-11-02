#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
LinkedList<T>* push(LinkedList<T>* l, T value)
{
    LinkedList<T>* newl = new LinkedList<T>;
    newl->value = value;
    newl->next = l;
    return newl;
}

template <class T>
T peek(LinkedList<T>* l)
{
    if (l == NULL) return 0;
    return l->value;
}

template <class T>
LinkedList<T>* pop(LinkedList<T>* l)
{
    if (l == NULL) return NULL;
    LinkedList<T>* next = l->next;
    delete l;
    return next;
}

template <class T>
void destroy(LinkedList<T>* l)
{
    while (l != NULL)
        l = pop(l);
}

template <class T>
void print(LinkedList<T>* l)
{
    for (LinkedList<T>* p = l; p != NULL; p = p->next)
        cout << p->value << " ";
    cout << endl;
}

template <class T>
LinkedList<T>* copy(LinkedList<T>* l)
{
    if (l == NULL)
        return NULL;

    LinkedList<T>* newl = new LinkedList<T>;
    newl->value = l->value;
    newl->next = copy(l->next);
    return newl;
}

template <class T>
LinkedList<T>* getIth(LinkedList<T>* l, int i)
{
    return getIthPrev(l, i).second;
}

template <class T>
std::pair<LinkedList<T>*, LinkedList<T>*> getIthPrev(LinkedList<T>* l, int i)
{
    assert(i >= 0);
    LinkedList<T>* prev = NULL;
    while (l != NULL && i != 0) {
        prev = l;
        l = l->next;
        i--;
    }

    return make_pair(prev, l);
}
