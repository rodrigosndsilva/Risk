#include "../include/Dune.h"
using namespace std;

int Dune::cont = 1;

Dune::Dune(std::string name, int resistance, int productCreation,
             int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Dune::~Dune() { cout << name << " Deleted" << endl; }

// string Dune::print() const {
//   ostringstream os;
//   os << "Name: " << name << Territory::print();
//   return os.str();
// }