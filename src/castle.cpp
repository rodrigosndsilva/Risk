#include "../include/Castle.h"
using namespace std;

int Castle::cont = 1;

Castle::Castle(std::string name, int resistance, int productCreation,
               int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Castle::~Castle() { cout << name << " Deleted" << endl; }

// string Castle::print() const {
//   ostringstream os;
//   os << "Name: " << name << Territory::print();
//   return os.str();
// }

void Castle::updateTerritoryProduction(int turn) {
  if (turn == 1 || turn == 2 || turn == 6 || turn == 7) {
    SetProductCreation(3);
  } else {
    SetProductCreation(0);
  }
}