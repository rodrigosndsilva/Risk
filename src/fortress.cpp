#include "../include/Fortress.h"
using namespace std;

int Fortress::cont = 1;

Fortress::Fortress(std::string name, int resistance, int productCreation,
                   int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Fortress::~Fortress() { cout << name << " Deleted" << endl; }

// string Fortress::print() const {
//   ostringstream os;
//   os << "Name: " << name << Territory::print();
//   return os.str();
// }

