#include "../include/Defenses.h"
using namespace std;

Defenses::Defenses(string name, int price) : Technology(name, price) {
  ostringstream os;
  os << "Adds 1 unit to the resistance of the invaded territory during an "
        "invasion event.";
  this->description = os.str();
  this->name = name;
  cout << name << " Tecnology Created!" << endl;
}

Defenses::~Defenses() { cout << GetName() << " Tecnology Deleted!" << endl; }

void Defenses::activateTecnology(Empire *e) {
  e->SetSafe(e->GetSafe() - GetPrice());
}