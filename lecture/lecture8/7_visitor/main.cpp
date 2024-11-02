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
        return new Mage(id);
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

    // Use of visitors
    MoveVisitor movVis(3, 4);
    applyVisitor(units, movVis);
    cout << string(30, '-') << endl;
    AttackVisitor atkVis(units[0]);
    applyVisitor(units, atkVis);
    cout << string(30, '-') << endl;
    CastVisitor cstVis(units[0], "Lightning Strike");
    applyVisitor(units, cstVis);

    // Delete units
    for (Unit* u: units)
        delete u;
    return 0;
}
