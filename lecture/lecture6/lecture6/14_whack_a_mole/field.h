#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "mole.h"
#include <Vector.h>
#include <ostream>

// The field where moles happily live
class Field {
public:
    // Constructor
    Field(int sz);

    // Get the information of a mole (if any)
    bool getMole(int row, int col, bool& big) const;

    // Add a mole
    bool addMole(int row, int col, bool big);

    // Remove mole
    bool removeMole(int row, int col);

    // Display the field
    void display(std::ostream& os);

    // has Mole left?
    bool hasMole() const;

    // Randomly place the moles
    void randomize();

private:
    // Size (n x n) of the filed
    int size;
    // Moles in the field
    Vector<Mole> moles;
};

#endif // FIELD_H_INCLUDED
