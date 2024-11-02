#include <iostream>
#include <string>
using namespace std;

class Unit {
public:
    virtual int getMovPts() const { return 0; };
    virtual string getSymbol() const { return "None"; };
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


int main()
{
    Footman f;
    Unit& u = f;
    cout << "Move Points: " << u.getMovPts() << endl;
    cout << "Unit Type: " << u.getSymbol() << endl;

    Unit* p = &f;
    cout << "Move Points: " << p->getMovPts() << endl;
    cout << "Unit Type: " << p->getSymbol() << endl;

    return 0;
}
