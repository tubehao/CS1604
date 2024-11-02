#include <iostream>
#include <string>
#include <Random.h>
#include <cassert>
using namespace std;

class Unit {
public:
    virtual int getMovPts() const = 0;
    virtual string getSymbol() const = 0;
};

class Footman : public Unit {
public:
    virtual int getMovPts() const
    {  return 3;  }

    virtual string getSymbol() const
    {  return "FT";  }
};

class Knight : public Unit {
public:
    virtual int getMovPts() const
    {  return 5;  }

    virtual string getSymbol() const
    {  return "KN";  }
};

class Archer : public Unit {
public:
    virtual int getMovPts() const
    {  return 3;  }

    virtual string getSymbol() const
    {  return "AR";  }
};


class Mage : public Unit {
public:
    virtual int getMovPts() const
    {  return 2;  }

    virtual string getSymbol() const
    {  return "MG";  }
};

Unit* generateUnit()
{
    int i = randomInteger(1, 4);
    switch (i) {
    case 1:
        return new Footman;
    case 2:
        return new Knight;
    case 3:
        return new Archer;
    case 4:
        return new Mage;
    }

    assert(false);
}

void printUnit(Unit* u)
{
    cout << "Unit: " << u->getSymbol() << "  Movement: " << u->getMovPts() << endl;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        Unit* u = generateUnit();
        printUnit(u);
        delete u;
    }

    return 0;
}
