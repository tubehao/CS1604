#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED

#include <string>

class ActionVisitor;

class Unit {
public:
    Unit(int uid) : id(uid) {}
    virtual int getMovPts() const = 0;
    virtual std::string getSymbol() const = 0;
    virtual void accept(ActionVisitor& vis) = 0;

    int getID() const { return id; }
private:
    int id;
};

class Footman : public Unit {
public:
    Footman(int uid) : Unit(uid) {}
    virtual int getMovPts() const;
    virtual std::string getSymbol() const;
    virtual void accept(ActionVisitor& vis);
};

class Knight : public Unit {
public:
    Knight(int uid) : Unit(uid) {}
    virtual int getMovPts() const;
    virtual std::string getSymbol() const;
    virtual void accept(ActionVisitor& vis);
};

class Archer : public Unit {
public:
    Archer(int uid) : Unit(uid) {}
    virtual int getMovPts() const;
    virtual std::string getSymbol() const;
    virtual void accept(ActionVisitor& vis);
};


class Mage : public Unit {
public:
    Mage(int uid, bool resist)
        : Unit(uid), rsMagic(resist) {}
    virtual int getMovPts() const;
    virtual std::string getSymbol() const;
    virtual void accept(ActionVisitor& vis);

    bool resistMagic() const
    {  return rsMagic;  }
private:
    bool rsMagic;
};

#endif // UNIT_H_INCLUDED
