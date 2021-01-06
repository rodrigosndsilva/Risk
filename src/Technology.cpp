#include "../include/Technology.h"
using namespace std;

Technology::Technology(string name, int price) {
  this->name = name;
  this->price = price;
  this->isAcquire = false;
}

Technology::~Technology() {
  cout << GetName() << " Base Tecnology Deleted!" << endl;
}

string Technology::print() const {
  ostringstream os;
  os << "Name: " << GetName() << "\t\tPrice (Gold): " << GetPrice()
     << "\t\tResume: " << GetDescription() << "\t\tAcquire: " << GetIsAcquire()
     << "\tVictory Points: 1" << endl;
  ;
  return os.str();
}