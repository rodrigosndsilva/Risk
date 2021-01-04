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

bool Fishing::canBeConquered(Empire *e) {
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

void Fishing::updateTerritoryProduction(int turn) {
  if (turn > 6) {
    SetProductCreation(4);
  } else {
    SetProductCreation(2);
  }
}