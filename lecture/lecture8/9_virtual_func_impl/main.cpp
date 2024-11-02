#include <iostream>
#include <string>
using namespace std;

//
// Base class
// It uses virtual table to implement virtual functions
//
class Unit {
public:
    //
    // Virtual table for Unit
    // It contains function pointers to two virtual member functions
    // 1. int getMovPts(const Unit* this);
    // 2. string getSymbol(const Unit* this);
    //
    void *vtbl[2] = {0};

    //
    // Function for getting movement points
    //
    int getMovPts() const{
        return reinterpret_cast<int (*)(const Unit*)>(vtbl[0])(this);
    }

    //
    // Function for getting the symbol
    //
    string getSymbol() const {
        return reinterpret_cast<string (*)(const Unit*)>(vtbl[1])(this);
    }
};

//
// Prototypes used by subclasses of Unit
//
int getMovPtsFootman(const Unit *u);
string getSymbolFootman(const Unit *u);
int getMovPtsKnight(const Unit *u);
string getSymbolKnight(const Unit *u);

//
// Footman
//
class Footman : public Unit {
public:
    Footman() : mpts(3) {
        vtbl[0] = reinterpret_cast<void*>(getMovPtsFootman);
        vtbl[1] = reinterpret_cast<void*>(getSymbolFootman);
    }

    int mpts;
};

//
// Functions that implements virtual functions for Footman
//
int getMovPtsFootman(const Unit *u)
{
    const Footman *f = static_cast<const Footman*>(u);
    return f->mpts;
}

string getSymbolFootman(const Unit *u)
{
    return "FT";
}

//
// Knight
//
class Knight : public Unit {
public:
    Knight() : mpts(5) {
        vtbl[0] = reinterpret_cast<void*>(getMovPtsKnight);
        vtbl[1] = reinterpret_cast<void*>(getSymbolKnight);
    }

    int mpts;
};

//
// Functions that implements virtual functions for Footman
//
int getMovPtsKnight(const Unit *u)
{
    const Knight *k = static_cast<const Knight*>(u);
    return k->mpts;
}

string getSymbolKnight(const Unit *u)
{
    return "KN";
}


//
// Main
//
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
