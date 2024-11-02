#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <cstddef>
#include <utility>

struct LinkedList{
    LinkedList() : value(0), next(NULL) {}
    int value;
    LinkedList* next;
};

LinkedList* push(LinkedList* l, int value);
int peek(LinkedList* l);
LinkedList* pop(LinkedList* l);
void destroy(LinkedList* l);
void print(LinkedList* l);

LinkedList* getIth(LinkedList* l, int i);
std::pair<LinkedList*, LinkedList*> getIthPrev(LinkedList* l, int i);
LinkedList* copy(LinkedList* l);

#endif // LINKEDLIST_H_INCLUDED
