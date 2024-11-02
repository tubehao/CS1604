#ifndef MOLE_H_INCLUDED
#define MOLE_H_INCLUDED

// Mole
class Mole {
public:
    // Constructor
    Mole(int r, int c, bool bg);

    // Get the status of the mole
    bool isBig() const;
    int getRow() const;
    int getCol() const;

private:
    // True denotes a big mole, false a smaller one
    bool big;
    // Coordinate of the mole
    int row, col;
};


#endif // MOLE_H_INCLUDED
