#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "mole.h"
#include <Grid.h>
#include <ostream>

// The field where moles happily live
class Field {
public:
    // Constructor
    Field(int sz);

    // Destructor
    ~Field();

    // Get the information of a mole (if any)
    const Mole* getMole(int row, int col) const;

    // Add a mole
    const Mole* addMole(int row, int col, bool big);

    // Remove mole
    bool removeMole(int row, int col);

    // Display the field
    void display(std::ostream& os);

    // has Mole left?
    bool hasMole() const;

    // Randomly place the moles
    void randomize();

    bool inBounds(int row, int col) const;

private:
    // Size (n x n) of the filed
    int size;
    // Moles in the field
    Grid<Mole*> moles;
};

#endif // FIELD_H_INCLUDED
