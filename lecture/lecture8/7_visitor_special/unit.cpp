#include "unit.h"
#include "visitor.h";

using namespace std;

/** Footman **/
int Footman::getMovPts() const
{  return 3;  }

string Footman::getSymbol() const
{  return "FT_" + to_string(getID());  }

void Footman::accept(ActionVisitor& vis)
{  vis.visitFootman(*this); }


/** Knight **/
int Knight::getMovPts() const
{  return 5;  }

string Knight::getSymbol() const
{  return "KN_" + to_string(getID());  }

void Knight::accept(ActionVisitor& vis)
{  vis.visitKnight(*this); }

/** Archer **/
int Archer::getMovPts() const
{  return 3;  }

string Archer::getSymbol() const
{  return "AR_" + to_string(getID());  }

void Archer::accept(ActionVisitor& vis)
{  vis.visitArcher(*this); }


/** Mage **/
int Mage::getMovPts() const
{  return 2;  }

string Mage::getSymbol() const
{  return "MG_" + to_string(getID());  }

void Mage::accept(ActionVisitor& vis)
{  vis.visitMage(*this); }

