#include "fvector.h"

FVector::FVector(int l) : n(l)
{
    arr = new int[l];
}

FVector::~FVector()
{
    delete[] arr;
}

int FVector::length() const
{
    return n;
}

int FVector::at(int i) const
{
    if (i >= 0 && i < n)
        return arr[i];
    return -1;
}

void FVector::set(int i, int v)
{
    if (i >= 0 && i < n) {
        arr[i] = v;
    }
}
