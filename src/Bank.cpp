#include "../include/Bank.h"
using namespace std;

Bank::Bank(string name, int price) : Technology(name, price) {
  ostringstream os;
  os << "This technology raises the maximum limit of military strength to 5.";
  this->description = os.str();
  this->name = name;
  cout << name << " Tecnology Created!" << endl;
}

Bank::~Bank() { cout << GetName() << " Tecnology Deleted!" << endl; }

void Bank::activateTecnology(Empire *e) {
  e->SetSafe(e->GetSafe() - GetPrice());
  e->SetMaxSafe(5);
  e->SetMaxWarehouse(5);
}