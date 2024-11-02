#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "LinkedList.h"

template <class T>
class Vector{
public:
    Vector() : lst(NULL) {}
    ~Vector()
    {
        clear();
    }

    //Copy constructor
    Vector(const Vector& vec)
    {
        lst = copy(vec.lst);
    }

    //Assignment operator
    Vector& operator=(const Vector& vec)
    {
        if (this != &vec) {
            clear();
            lst = copy(vec.lst);
        }
        return *this;
    }

    int size() const
    {
        int i = 0;
        LinkedList<T>* l = lst;
        while (l != NULL) {
            i++;
            l = l->next;
        }
        return i;
    }

    bool isEmpty() const
    {
        return lst == NULL;
    }

    void clear()
    {
        destroy(lst);
        lst = NULL;
    }

    T get(int i) const
    {
        if (i < 0) return 0;

        LinkedList<T>* l = getIth(lst, i);
        if (l == NULL)
            return T();
        else
            return l->value;
    }

    void set(int i, T v)
    {
        if (i < 0) return;

        LinkedList<T>* l = getIth(lst, i);
        if (l != NULL)
            l->value = v;
    }

    void add(T v)
    {
        LinkedList<T> *prev = NULL, *cur = lst;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
        }

        LinkedList<T>* newl = new LinkedList<T>(v);
        if (prev != NULL)
            prev->next = newl;
        else
            lst = newl;
    }

    void insert(int i, T v)
    {
        if (i < 0) return;

        std::pair<LinkedList<T>*, LinkedList<T>*> p = getIthPrev(lst, i);
        LinkedList<T> *prev = p.first, *cur = p.second;

        LinkedList<T>* newl = new LinkedList<T>(v);
        newl->next = cur;
        if (prev != NULL)
            prev->next = newl;
        else
            lst = newl;
    }

    void remove(int i)
    {
        if (i < 0) return;

        std::pair<LinkedList<T>*, LinkedList<T>*> p = getIthPrev(lst, i);
        LinkedList<T> *prev = p.first, *cur = p.second;

        if (cur == NULL) return;

        if (prev != NULL)
            prev->next = cur->next;
        else
            lst = cur->next;
    }

private:
    LinkedList<T>* lst;
};

#endif // VECTOR_H_INCLUDED
