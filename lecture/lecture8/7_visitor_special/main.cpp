#include <iostream>
#include <string>
#include <Random.h>
#include <cassert>
#include <Vector.h>
#include "unit.h"
#include "visitor.h"
using namespace std;


Unit* generateUnit(int id)
{
    int i = randomInteger(1, 4);
    switch (i) {
    case 1:
        return new Footman(id);
    case 2:
        return new Knight(id);
    case 3:
        return new Archer(id);
    case 4:
        return new Mage(id, false);
    }

    assert(false);
}

void printUnit(Unit* u)
{
    cout << "Unit: " << u->getSymbol() << "  Movement: " << u->getMovPts() << endl;
}

void applyVisitor(Vector<Unit*>& units, ActionVisitor& vis)
{
    for (Unit* u: units)
        u->accept(vis);
}

int main()
{
    // Create units
    Vector<Unit*> units;
    for (int i = 0; i < 10; i++) {
        Unit* u = generateUnit(i);
        units.add(u);
    }

    // Special casts
    Mage* mg = new Mage(999,true);
    CastMageVisitor cstMgVis(mg, "Fire storm");
    applyVisitor(units, cstMgVis);
    delete mg;

    cout << string(30, '-') << endl;

    Mage* mg1 = new Mage(1000,false);
    CastMageVisitor cstMgVis1(mg1, "Fire storm");
    applyVisitor(units, cstMgVis1);
    delete mg1;

    // Delete units
    for (Unit* u: units)
        delete u;
    return 0;
}
