#include "../include/Missiles.h"
using namespace std;

Missiles::Missiles(string name, int price) : Technology(name, price) {
  ostringstream os;
  os << "This technology serves to conquer islands.";
  this->description = os.str();
  this->name = name;
  cout << name << " Tecnology Created!" << endl;
}

Missiles::~Missiles() { cout << GetName() << " Tecnology Deleted!" << endl; }

void Missiles::activateTecnology(Empire *e) {
  e->SetSafe(e->GetSafe() - GetPrice());
}