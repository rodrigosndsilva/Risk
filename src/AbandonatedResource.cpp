#include "../include/AbandonatedResource.h"
using namespace std;

AbandonatedResource::AbandonatedResource(string name, int num)
    : Event(name, num) {
  this->name = name;
  this->num = num;
  cout << name << " Event Created!" << endl;
}

AbandonatedResource::~AbandonatedResource() {
  cout << GetName() << " Deleted!" << endl;
}

void AbandonatedResource::activateEvent(Empire *e, int turn) {
  cout << "---> Abandoned Resource Event! <---" << endl;
  if (turn <= 6) { // recebe prod
    if (e->GetWarehouse() < e->GetMaxWarehouse()) {
      e->SetWarehouse(e->GetWarehouse() + 1);
      cout << "You found an abandoned product in the first year!\nWarehouse is "
              "now "
              "<"
           << e->GetWarehouse() << ">" << endl;
    } else {
      cout << "You found an abandoned product in the first year, but your "
              "warehouse is full, so the product has been destroyed!"
           << endl;
    }
  } else { // recebe ouro
    if (e->GetSafe() < e->GetMaxSafe()) {
      e->SetSafe(e->GetSafe() + 1);
      cout << "You found an abandoned gold in the second year!\nSafe is now "
              "<"
           << e->GetSafe() << ">" << endl;
    } else {
      cout << "You found an abandoned gold in the first year, but your "
              "safe is full, so the gold has been destroyed!"
           << endl;
    }
  }
}