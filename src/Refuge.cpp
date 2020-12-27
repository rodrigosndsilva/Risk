#include "../include/Refuge.h"
using namespace std;

int Refuge::cont = 1;

Refuge::Refuge(std::string name, int resistance,
                           int productCreation, int goldCreation,
                           bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Refuge::~Refuge() { cout << Getname() << " Deleted" << endl; }

bool Refuge::canBeConquered(int numTerr) {
  if (numTerr >= 5)
    return true;
  return false;
}