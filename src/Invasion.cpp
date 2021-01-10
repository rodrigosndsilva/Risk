#include "../include/Invasion.h"
using namespace std;

Invasion::Invasion(string name, int num) : Event(name, num) {
  this->name = name;
  this->num = num;
  cout << name << " Event Created!" << endl;
}

Invasion::~Invasion() { cout << GetName() << " Deleted!" << endl; }

void Invasion::activateEvent(Empire *e, int turn) {
  int flag = 0;
  cout << "---> Invasion Event! <---" << endl;
  /* generate secret number between 1 and 6: */
  for (auto *x : e->GetOwnedTechnologies()) {
    if (x->GetName().compare("Defenses") == 0) {
      flag = 1;
    }
  }
  int randNum = rand() % 6 + 1;
  cout << "Luck factor generated on Invasion Event: " << randNum << endl;
  if (turn <= 6) { // primeiro turno
    if ((randNum + 2) >=
        (e->GetOwnedTerritories().back()->GetResistance() + flag)) {
      e->GetOwnedTerritories().back()->SetConquered(
          false); // coloca o territorio a false
      cout << "This territory: " << e->GetOwnedTerritories().back()->Getname()
           << " was invaded!" << endl;
      e->removelastTerritory(); // remove do vector o ultimo territorio
      // conquistado
    } else {
      cout << "This territory: <" << e->GetOwnedTerritories().back()->Getname()
           << "> was invaded but won the fight!!" << endl;
    }
  } else { // segundo turno
    if ((randNum + 3) >=
        (e->GetOwnedTerritories().back()->GetResistance() + flag)) {
      e->GetOwnedTerritories().back()->SetConquered(
          false); // coloca o territorio a false
      cout << "This territory: " << e->GetOwnedTerritories().back()->Getname()
           << " was invaded!" << endl;
      e->removelastTerritory(); // remove do vector o ultimo territorio
                                // conquistado
    } else {
      cout << "This territory: <" << e->GetOwnedTerritories().back()->Getname()
           << "> was invaded but won the fight!!" << endl;
    }
  }
}
