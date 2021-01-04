#include "../include/Refuge.h"
using namespace std;

int Refuge::cont = 1;

Refuge::Refuge(std::string name, int resistance, int productCreation,
               int goldCreation, bool conquered, int victoryPoints)
    : Territory(name, resistance, productCreation, goldCreation, conquered,
                victoryPoints) {
  ostringstream os;
  os << name << cont;
  this->name = os.str();
  cont++;
  cout << "Your " << this->name << " is Created\n";
}
Refuge::~Refuge() { cout << Getname() << " Deleted" << endl; }

bool Refuge::canBeConquered(Empire *e) {
  for (auto *x : e->GetOwnedTechnologies()) {
    if (Getname().compare(x->GetName()) == 0) {
      if (e->GetOwnedTerritories().size() >= 5) {
        return true;
      } else {
        cout << "The territory that you want to conquer is an island. You "
                "must have at least 5 territories to conquer an island!"
             << endl;
        return false;
      }
    }
  }
  cout << "The territory that you want to conquer is an island. You "
          "must have the Missiles Technology to conquer that territory!"
       << endl;
  return false;
}