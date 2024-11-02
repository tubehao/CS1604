#include "engine.h"
#include <Random.h>
#include <cassert>
using namespace std;

Field randomField(int size)
{
    Field f(size);

    // Every row has one mole
    for (int row = 0; row < size; row++) {
        int col = randomInteger(0, size-1);
        int big = randomBool();
        f.addMole(row, col, big);
    }

    return f;
}

// Score of the mole
int getScore(bool big)
{
    if (big)
        return 300;
    else
        return 100;
}

// Read row and column from the string
bool readRowCol(const string& str, int& row, int& col)
{
    stringstream ss(str);
    ss >> row >> col;
    if (ss)
        return true;
    else
        return false;
}

// Query row and column from input stream
bool queryRowCol(int& row, int& col)
{
    string line;
    if (!getline(cin, line)) {
        cout << "Read line failed!" << endl;
        assert(false);
    }

    if (!readRowCol(line, row, col)) {
        cout << "Incorrect input! "<< endl;
        return false;
    }

    return true;
}

// Play the game
void play(ostream& os, int size)
{
    int score = 0;
    int round = 1;
    Field f = randomField(size);

    os << "Game begins!" << endl;
    while (f.hasMole()) {
        f.display(os);
        os << "Round " << round << "! Your score is " << score << endl;
        os << endl;
        int r, c;
        while (true) {
            os << "Enter the coordinate: ";
            if (queryRowCol(r, c)) break;
        }
        if (!f.inBounds(r, c)) {
            cout << "Coordinate out of bounds!" << endl;
            continue;
        }

        // Check if you have whacked a mole and score
        const Mole* m = f.getMole(r, c);
        if (m != NULL) {
            bool big = m->isBig();
            os << "Whacked a " << (big ? "BIG" : "small") << " one!" << endl;
            score += getScore(big);
            // Remove the mole
            f.removeMole(r, c);
        } else {
            os << "Oops! Missed!" << endl;
            score -= 100;
        }

        // Randomize
        f.randomize();
        round++;
    }

    os << "Game ended!\nCongratulations! You score is " << score << endl;
}
