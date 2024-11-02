#include <iostream>
#include <Vector.h>
#include <cassert>
using namespace std;

template<class T>
Vector<Vector<T>> addHead(T v, const Vector<Vector<T>>& vecs)
{
    Vector<Vector<T>> result;
    for (int i = 0; i < vecs.size(); i++) {
        Vector<T> vec = vecs[i];
        vec.insert(0, v);
        result.add(vec);
    }

    return result;
}

template<class T>
Vector<Vector<T>> getSubseq(const Vector<T>& vec)
{
    if (vec.isEmpty()) {
        Vector<Vector<T>> emptySeq= {{}};
        return emptySeq;
    }
    else {
        // Get the subsequences of the tail
        Vector<T> svec = vec;
        svec.remove(0);
        Vector<Vector<T>> tvecs = getSubseq(svec);
        Vector<Vector<T>> hvecs = addHead(vec[0], tvecs);

        return tvecs + hvecs;
    }
}


int main()
{
    Vector<int> vec = {42, -13, 101};

    Vector<Vector<int>> result = getSubseq(vec);
    cout << result << endl;

    return 0;
}
