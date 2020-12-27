#include "../include/Plain.h"
using namespace std;

int Plain::cont = 1;

Plain::Plain(std::string name, int resistance, int productCreation,
             int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Plain::~Plain() { cout << Getname() << " Deleted" << endl; }

void Plain::updateTerritoryProduction(int turn) {
  if (turn > 6) {
    SetProductCreation(2);
  } else {
    SetProductCreation(1);
  }
}