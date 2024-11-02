#include "field.h"
#include <iomanip>
#include <Random.h>
using namespace std;

// Constructor
Field::Field(int sz)
    : size(sz), moles(size, size)
{}

// Destructor
Field::~Field()
{
    for (Mole* m : moles) {
        if (m != NULL)
            delete m;
    }
}

// Get the information of a mole (if any)
const Mole* Field::getMole(int row, int col) const
{
    return moles[row][col];
}

// Add a mole
const Mole* Field::addMole(int row, int col, bool big)
{
    if (getMole(row, col) != NULL)
        return NULL;

    Mole* m = new Mole(row, col, big);
    moles[row][col] = m;
    return m;
}

// Remove mole
bool Field::removeMole(int row, int col)
{
    Mole* m = moles[row][col];
    if (m != NULL) {
        delete m;
        moles[row][col] = NULL;
        return true;
    } else
        return false;
}

// Has mole left?
bool Field::hasMole() const
{
    for (Mole* m : moles)
        if (m != NULL)
            return true;
    return false;
}

// Randomize the field
void Field::randomize()
{
    Grid<Mole*> grd(size, size);

    for (Mole* m: moles) {
        while (true) {
            int nrow = randomInteger(0, size-1);
            int ncol = randomInteger(0, size-1);
            if (grd[nrow][ncol] == NULL) {
                grd[nrow][ncol] = m;
                break;
            }
        }
    }

    moles = grd;
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
            const Mole* m = getMole(i,j);
            if (m != NULL) {
                if (m->isBig())
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


bool Field::inBounds(int r, int c) const
{
    return moles.inBounds(r, c);
}
