#include "../include/Mountain.h"
using namespace std;

int Mountain::cont = 1;

Mountain::Mountain(std::string name, int resistance, int productCreation,
                   int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  SetContProductions(0);
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Mountain::~Mountain() { cout << name << " Deleted" << endl; }

// string Mountain::print() const {
//   ostringstream os;
//   os << "ContProduction: " << contProductions << Territory::print();
//   return os.str();
// }

void Mountain::updateTerritoryProduction(int turn) {
  if (turn > 0) {
    if (GetConquered() == true) {
      SetContProductions(GetContProductions() + 1);
      if (GetContProductions() > 2) {
        SetProductCreation(1);
      } else {
        SetProductCreation(0);
      }
    }
  }
}