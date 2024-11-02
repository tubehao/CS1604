#include "visitor.h"
#include <iostream>
using namespace std;

/** MoveVisitor **/
void moveAction(Unit& u, int x, int y)
{
    cout << "Move " << u.getSymbol()
         << ": Movement Points " << u.getMovPts()
         << ": Move to (" << x << "," << y << ")" << endl;
}

bool MoveVisitor::visitFootman(Footman& ft)
{
    moveAction(ft, x, y);
    return true;
}

bool MoveVisitor::visitKnight(Knight& kn)
{
    moveAction(kn, x, y);
    return true;
}

bool MoveVisitor::visitArcher(Archer& ar)
{
    moveAction(ar, x, y);
    return true;
}

bool MoveVisitor::visitMage(Mage& mg)
{
    moveAction(mg, x, y);
    return true;
}

/** AttackVisitor **/
void attackAction(Unit& src, Unit& tgt)
{
    cout << src.getSymbol()
         << ": attacks: "
         << tgt.getSymbol() << endl;
}

void attackNoAction(Unit& u)
{
    cout << u.getSymbol() << ": cannot attack!" << endl;
}

bool AttackVisitor::visitFootman(Footman& ft)
{
    attackAction(ft, *target);
    return true;
}

bool AttackVisitor::visitKnight(Knight& kn)
{
    attackAction(kn, *target);
    return true;
}

bool AttackVisitor::visitArcher(Archer& ar)
{
    attackNoAction(ar);
    return false;
}

bool AttackVisitor::visitMage(Mage& mg)
{
    attackNoAction(mg);
    return false;
}

/** CastVisitor **/
void castAction(Unit& src, Unit& tgt, string spell)
{
    cout << src.getSymbol()
         << ": casts " << spell << " at: "
         << tgt.getSymbol() << endl;
}

void castNoAction(Unit& u)
{
    cout << u.getSymbol() << ": cannot cast spell!" << endl;
}

bool CastVisitor::visitFootman(Footman& ft)
{
    castNoAction(ft);
    return false;
}

bool CastVisitor::visitKnight(Knight& kn)
{
    castNoAction(kn);
    return false;
}

bool CastVisitor::visitArcher(Archer& ar)
{
    castNoAction(ar);
    return false;
}

bool CastVisitor::visitMage(Mage& mg)
{
    castAction(mg, *target, spellName);
    return true;
}
