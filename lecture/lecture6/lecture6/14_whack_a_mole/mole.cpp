#include "mole.h"

// Constructor
Mole::Mole(int r, int c, bool bg)
    : big(bg), row(r), col(c)
{}

// Get the status of the mole
bool Mole::isBig() const
{
    return big;
}

int Mole::getRow() const
{
    return row;
}

int Mole::getCol() const
{
    return col;
}
