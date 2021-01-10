#include "../include/Drones.h"
using namespace std;

Drones::Drones(string name, int price) : Technology(name, price) {
  ostringstream os;
  os << "This technology raises the maximum limit of military strength to 5.";
  this->description = os.str();
  this->name = name;
  cout << name << " Tecnology Created!" << endl;
}

Drones::~Drones() { cout << GetName() << " Tecnology Deleted!" << endl; }

void Drones::activateTecnology(Empire *e) {
  e->SetSafe(e->GetSafe() - GetPrice());
  e->SetMaxMilitaryForce(5);
}