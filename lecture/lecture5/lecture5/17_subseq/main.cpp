#include <iostream>
#include <Vector.h>
#include <cassert>
using namespace std;

Vector<Vector<int>> addHead(int v, const Vector<Vector<int>>& vecs)
{
    Vector<Vector<int>> result;
    for (int i = 0; i < vecs.size(); i++) {
        Vector<int> vec = vecs[i];
        vec.insert(0, v);
        result.add(vec);
    }

    return result;
}

Vector<Vector<int>> getSubseq(const Vector<int>& vec)
{
    if (vec.isEmpty()) {
        Vector<Vector<int>> emptySeq= {};
        return emptySeq;
    }
    else {
        // Get the subsequences of the tail
        Vector<int> svec = vec;
        svec.remove(0);
        Vector<Vector<int>> tvecs = getSubseq(svec);
        Vector<Vector<int>> hvecs = addHead(vec[0], tvecs);

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
