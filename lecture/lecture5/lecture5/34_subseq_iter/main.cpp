#include <iostream>
#include <Queue.h>
#include <Vector.h>
using namespace std;

Queue<Vector<int>> findSubseqs(const Vector<int>& vec)
{
    Queue<Vector<int>> subSeqs = { {} };

    for (int i = 0; i < vec.size(); i++) {

        int n = subSeqs.size();

        for (int j = 0; j < n; j++) {
            Vector<int> s = subSeqs.dequeue();

            // Not include the i-th element
            subSeqs.enqueue(s);
            // Include the i-th element
            s.add(vec[i]);
            subSeqs.enqueue(s);
        }
    }

    return subSeqs;
}

int main()
{
    Vector<int> vec = {42, -13, 101};
    Vector<int> vec1 = {32, 112, 0, 9};


    cout << findSubseqs(vec) << endl;
    cout << findSubseqs(vec1) << endl;

    return 0;
}
