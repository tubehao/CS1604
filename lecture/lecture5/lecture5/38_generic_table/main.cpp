#include <iostream>
#include <Vector.h>
using namespace std;

// Find the entry with the key and return the index
// Return -1 if there is no such index
template <class T, class S>
int findEntry(const Vector<pair<T, S>>& table, T key)
{
    for (int i = 0; i < table.size(); i++)
        if (table[i].first == key)
            return i;
    return -1;
}

// Add an entry to the table if there is no entry with key
template <class T, class S>
bool addEntry(Vector<pair<T, S>>& table, T key, S value)
{
    if (findEntry(table, key) >= 0)
        return false;

    table.add(make_pair(key, value));
    return true;
}

// Remove an entry from the table
template <class T, class S>
void removeEntry(Vector<pair<T, S>>& table, T key)
{
    int i = findEntry(table, key);
    if (i < 0) return;

    table.remove(i);
}

// Print the  table
template <class T, class S>
void printTable(const Vector<pair<T, S>>& table)
{
    cout << "{";
    for (int i = 0; i < table.size(); i++)
        cout << "(" << table[i].first << ", " << table[i].second << "); ";
    cout << "}" << endl;
}

int main()
{
    Vector<pair<string, int>> table;

    addEntry<string, int>(table, "ZhangSan", 13300010002);
    addEntry<string, int>(table, "LiSi", 13912345678);
    addEntry<string, int>(table, "WangWu", 13507071212);

    printTable(table);

    cout << findEntry<string,int>(table, "WangWu") << endl;

    removeEntry<string, int>(table, "WangWu");
    printTable(table);

    cout << findEntry<string,int>(table, "WangWu") << endl;


    return 0;
}
