#include "../include/Alliance.h"
using namespace std;

Alliance::Alliance(string name, int num) : Event(name, num) {
  this->name = name;
  this->num = num;
  cout << name << " Event Created!" << endl;
}

Alliance::~Alliance() { cout << GetName() << " Deleted!" << endl; }

void Alliance::activateEvent(Empire *e, int turn) {
  cout << "---> Alliance Event! <---" << endl;
  if (turn >= 0) {
    if (e->GetMilitaryForce() < e->GetMaxMilitaryForce()) {
      e->SetMilitaryForce(e->GetMilitaryForce() + 1);
      cout
          << "An alliance was signed with another empire for which there is no "
             "record. As a consequence of this, military force increases a "
             "unit.\nMilitary force: <"
          << e->GetMilitaryForce() << ">" << endl;
    } else {
      cout
          << "An alliance was signed with another empire for which there is no "
             "record. As a result, military strength increases by one, but if "
             "you have the maximum Military Strength, you can't get an extra "
             "one!"
          << endl;
    }
  }
}
