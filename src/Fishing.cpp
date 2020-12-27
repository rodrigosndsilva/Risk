#include "../include/Fishing.h"
using namespace std;

int Fishing::cont = 1;

Fishing::Fishing(std::string name, int resistance, int productCreation,
                 int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Fishing::~Fishing() { cout << Getname() << " Deleted" << endl; }

bool Fishing::canBeConquered(int numTerr) {
  if (numTerr >= 5)
    return true;
  return false;
}

void Fishing::updateTerritoryProduction(int turn) {
  if (turn > 6) {
    SetProductCreation(4);
  } else {
    SetProductCreation(2);
  }
}