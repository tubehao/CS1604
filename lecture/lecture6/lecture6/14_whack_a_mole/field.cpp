#include "field.h"
#include <iomanip>
#include <Random.h>
using namespace std;

// Constructor
Field::Field(int sz)
    : size(sz)
{}

// Get the information of a mole (if any)
bool Field::getMole(int row, int col, bool& big) const
{
    for (int i = 0; i < moles.size(); i++) {
        Mole m = moles[i];
        if (m.getRow() == row && m.getCol() == col) {
            big = m.isBig();
            return true;
        }
    }
    return false;
}

// Add a mole
bool Field::addMole(int row, int col, bool big)
{
    bool sz;
    if (getMole(row, col, sz))
        return false;

    moles.add(Mole(row, col, big));
    return true;
}

// Remove mole
bool Field::removeMole(int row, int col)
{
    for (int i = 0; i < moles.size(); i++) {
        Mole m = moles[i];
        if (m.getRow() == row && m.getCol() == col) {
            moles.remove(i);
            return true;
        }
    }

    return false;
}

// Has mole left?
bool Field::hasMole() const
{
    return !moles.isEmpty();
}

// Randomize the field
void Field::randomize()
{
    Field newField(size);

    for (int i = 0; i < moles.size(); i++) {
        Mole m = moles[i];
        while (true) {
            int nrow = randomInteger(0, size-1);
            int ncol = randomInteger(0, size-1);
            if (newField.addMole(nrow, ncol, m.isBig()))
                break;
        }
    }

    moles = newField.moles;
}

// Print the horizontal line
void printHLine(ostream& os, int n)
{
    os << "  ";
    for (int i = 0; i < n; i++)
        os << "+--";
    os << "+" << endl;
}

// Display the field
void Field::display(std::ostream& os)
{
    // Print the x coordinates
    os << "  ";
    for (int i = 0; i < size; i++)
        os << ' ' << setw(2) << i;
    os << endl;

    printHLine(os, size);
    for (int i = 0; i < size; i++) {
        os << setw(2) << i;
        for (int j = 0; j < size; j++) {
            os << '|';
            // Print the mole
            bool big;
            if (getMole(i, j, big)) {
                if (big)
                    os << "M ";
                else
                    os << "m ";
            } else
                os << "  ";
        }
        os << '|' << endl;
        printHLine(os, size);
    }
    os << endl;
}
