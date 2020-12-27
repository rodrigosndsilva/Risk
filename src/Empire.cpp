#include "../include/Empire.h"
using namespace std;

Empire::Empire() {
  safe = 0;      // gold
  warehouse = 0; // products
  maxSafe = 3;
  maxWarehouse = 3;
  militaryForce = 0;
  maxMilitaryForce = 3;
  cout << "Your Empire is Created\n";
}

Empire::~Empire() { cout << "Empire Deleted\n"; }

void Empire::addownedTerritory(Territory *t) { ownedTerritories.push_back(t); }

string Empire::print() const {
  ostringstream os;
  os << "Safe: " << safe << "/" << maxSafe << "\nWarehouse: " << warehouse
     << "/" << maxWarehouse << "\nMilitary Force: " << militaryForce << "/"
     << maxMilitaryForce << endl;

  os << "Owned Territorys:\n";
  for (auto *x : ownedTerritories) {
    os << " -> " << x->Getname() << endl;
  }
  return os.str();
}

void Empire::collectGoldAndProductsFromTerritories() {
  for (auto *x : ownedTerritories) {
    if (safe != maxSafe) {
      safe += x->GetGoldCreation();
    }
  }
  for (auto *x : ownedTerritories) {
    if (warehouse != maxWarehouse) {
      warehouse += x->GetProductCreation();
    }
  }
}

void Empire::buymilitary() {
  if (safe > 0 && warehouse > 0) {
    if (militaryForce != maxMilitaryForce) {
      safe -= 1;
      warehouse -= 1;
      militaryForce += 1;
      cout << "Your Empire have one more military! Now you have <"
           << militaryForce << "> military!" << endl;
    } else {
      cout << "You have reached maximum military force!" << endl;
    }
  }
}