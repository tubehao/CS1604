#include <iostream>
#include <Vector.h>
using namespace std;

// Find the entry with the student name and return its index
// Return -1 if there is no such index
int findEntry(const Vector<pair<string, int>>& table, string name)
{
    for (int i = 0; i < table.size(); i++)
        if (table[i].first == name)
            return i;
    return -1;
}

// Add an entry to the table if there is no entry with name
bool addEntry(Vector<pair<string, int>>& table, string name, int number)
{
    if (findEntry(table, name) >= 0)
        return false;

    table.add(make_pair(name, number));
    return true;
}

// Remove an entry from the table
void removeEntry(Vector<pair<string, int>>& table, string name)
{
    int i = findEntry(table, name);
    if (i < 0) return;

    table.remove(i);
}

// Print the student table
void printTable(const Vector<pair<string, int>>& table)
{
    cout << "{";
    for (int i = 0; i < table.size(); i++)
        cout << "(" << table[i].first << ", " << table[i].second << "); ";
    cout << "}" << endl;
}

int main()
{
    Vector<pair<string, int>> table;

    addEntry(table, "ZhangSan", 13300010002);
    addEntry(table, "LiSi", 13912345678);
    addEntry(table, "WangWu", 13507071212);

    printTable(table);

    cout << findEntry(table, "WangWu") << endl;

    removeEntry(table, "WangWu");
    printTable(table);

    cout << findEntry(table, "WangWu") << endl;


    return 0;
}
