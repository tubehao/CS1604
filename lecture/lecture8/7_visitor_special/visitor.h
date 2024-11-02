#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include "unit.h"

class ActionVisitor {
public:
    virtual bool visitFootman(Footman& ft) = 0;
    virtual bool visitKnight(Knight& kn) = 0;
    virtual bool visitArcher(Archer& ar) = 0;
    virtual bool visitMage(Mage& mg) = 0;
};

class MoveVisitor: public ActionVisitor {
public:
    MoveVisitor(int xx, int yy) : x(xx), y(yy) {}
    virtual bool visitFootman(Footman& ft);
    virtual bool visitKnight(Knight& kn);
    virtual bool visitArcher(Archer& ar);
    virtual bool visitMage(Mage& mg);

private:
    int x, y;
};

class AttackVisitor : public ActionVisitor {
public:
    AttackVisitor(Unit* t) : target(t) {}

    virtual bool visitFootman(Footman& ft);
    virtual bool visitKnight(Knight& kn);
    virtual bool visitArcher(Archer& ar);
    virtual bool visitMage(Mage& mg);

private:
    Unit* target;
};

class CastVisitor: public ActionVisitor {
public:
    CastVisitor(Unit* t, std::string sname)
        : target(t), spellName(sname) {}

    virtual bool visitFootman(Footman& ft);
    virtual bool visitKnight(Knight& kn);
    virtual bool visitArcher(Archer& ar);
    virtual bool visitMage(Mage& mg);

    std::string getSpellName() const
    {
        return spellName;
    }
private:
    Unit* target;
    std::string spellName;
};

class CastMageVisitor: public CastVisitor {
public:
    CastMageVisitor(Mage* mg, std::string sname)
        : CastVisitor(mg, sname), target(mg) {}

    virtual bool visitMage(Mage& mg);

private:
    Mage* target;
};

/*
class ShootVisitor: public ActionVisitor {
public:
    ShootVisitor(Unit* t) : target(t) {}

    virtual bool visitFootman(Footman& ft);
    virtual bool visitKnight(Knight& kn);
    virtual bool visitArcher(Archer& ar);
    virtual bool visitMage(Mage& mg);
private:
    Unit* target;
};


enum Direction {NORTH, SOUTH, EAST, WEST};

class ChargeVisitor: public ActionVisitor {
public:
    ChargeVisitor(Direction direct) : dir(direct) {}

    virtual bool visitFootman(Footman& ft);
    virtual bool visitKnight(Knight& kn);
    virtual bool visitArcher(Archer& ar);
    virtual bool visitMage(Mage& mg);
private:
    Direction dir;
};
*/

#endif // VISITOR_H_INCLUDED
