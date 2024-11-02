#include "LinkedList.h"
#include "Vector.h"

IVector::IVector()
IVector::~IVector()
{
    clear();
}

//Copy constructor
IVector::IVector(const IVector& vec)
{
    lst = copy(vec.lst);
}

//Assignment operator
IVector& IVector::operator=(const IVector& vec)
{
    if (this != &vec) {
        clear();
        lst = copy(vec.lst);
    }
    return *this;
}


int IVector::size() const
{
    int i = 0;
    LinkedList<int>* l = lst;
    while (l != NULL) {
        i++;
        l = l->next;
    }
    return i;
}

bool IVector::isEmpty() const
{
    return lst == NULL;
}

void IVector::clear()
{
    destroy(lst);
    lst = NULL;
}

int IVector::get(int i) const
{
    if (i < 0) return 0;

    LinkedList<int>* l = getIth(lst, i);
    if (l == NULL)
        return 0;
    else
        return l->value;
}

void IVector::set(int i, int v)
{
    if (i < 0) return;

    LinkedList<int>* l = getIth(lst, i);
    if (l != NULL)
        l->value = v;
}

void IVector::add(int v)
{
    LinkedList<int> *prev = NULL, *cur = lst;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }

    LinkedList<int>* newl = new LinkedList<int>(v);
    if (prev != NULL)
        prev->next = newl;
    else
        lst = newl;
}

void IVector::insert(int i, int v)
{
    if (i < 0) return;

    std::pair<LinkedList<int>*, LinkedList<int>*> p = getIthPrev(lst, i);
    LinkedList<int> *prev = p.first, *cur = p.second;

    LinkedList<int>* newl = new LinkedList<int>(v);
    newl->next = cur;
    if (prev != NULL)
        prev->next = newl;
    else
        lst = newl;
}

void IVector::remove(int i)
{
    if (i < 0) return;

    std::pair<LinkedList<int>*, LinkedList<int>*> p = getIthPrev(lst, i);
    LinkedList<int> *prev = p.first, *cur = p.second;

    if (cur == NULL) return;

    if (prev != NULL)
        prev->next = cur->next;
    else
        lst = cur->next;
}
