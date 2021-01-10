#include "../include/Exchange.h"
using namespace std;

Exchange::Exchange(string name, int price) : Technology(name, price) {
  ostringstream os;
  os << "Commercial system that makes exchanges between products and gold "
        "possible, (collecting products and gold).";
  this->description = os.str();
  this->name = name;
  cout << name << " Tecnology Created!" << endl;
}

Exchange::~Exchange() { cout << GetName() << " Tecnology Deleted!" << endl; }

void Exchange::activateTecnology(Empire *e) {
  e->SetSafe(e->GetSafe() - GetPrice());
}