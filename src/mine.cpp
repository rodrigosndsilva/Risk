#include "../include/Mine.h"
using namespace std;

int Mine::cont = 1;

Mine::Mine(std::string name, int resistance, int productCreation,
           int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Mine::~Mine() { cout << name << " Deleted" << endl; }

// string Mine::print() const {
//   ostringstream os;
//   os << "Name: " << name << Territory::print();
//   return os.str();
// }

void Mine::updateTerritoryProduction(int turn) {
  if ((turn > 0 && turn < 4) || (turn > 5 && turn < 9)) {
    SetGoldCreation(1);
  } else {
    SetGoldCreation(2);
  }
}