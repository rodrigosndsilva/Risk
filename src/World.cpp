#include "../include/World.h"
using namespace std;

World::World() {
  this->empire = new Empire();
  addTerritory(new Territory("SafeHouse", 9, 1, 1, true, 0));
  Technologies.push_back(new Drones("Drones", 4));
  Technologies.push_back(new Drones("Drones2", 4));
  // Technologies.push_back(new Missiles("Missiles", 4));
  // Technologies.push_back(new Defenses("Defenses", 4));
  // Technologies.push_back(new Exchange("Exchange", 4));
  // Technologies.push_back(new Bank("Bank", 4));
  cout << "Your World is Created\n";
}

World::~World() {
  delete (empire);
  for (auto *x : Territories)
    delete x;
  for (auto *y : Technologies)
    delete y;
  cout << "World Deleted" << endl;
}
void World::addTerritory(Territory *t) {
  Territories.push_back(t);
  if (t->GetConquered() == true) {
    addEmpireTerritoryOwned(t);
  }
}
void World::addEmpireTerritoryOwned(Territory *t) {
  empire->addownedTerritory(t);
}

void World::print() const {
  cout << "\n\nTerritories:\n";
  for (auto *x : Territories) {
    cout << x->print();
  }
  cout << "\nTechnologies:\n";
  for (auto *x : Technologies) {
    cout << x->print();
  }
  cout << "\nEmpire:\n";
  cout << empire->print() << endl << endl;
}

void World::updateAllTerritoriesProductions(int turn) {
  for (auto *x : Territories) {
    x->updateTerritoryProduction(turn);
  }
}

void World::conquerTerritory(const string t) {
  if (empire->GetMilitaryForce() > 0) {
    for (auto *x : Territories) {
      if (t.compare(x->Getname()) == 0) {

        if (x->GetConquered()) {
          cout << "This territory is already conquered!" << endl;
          return;
        }
        if (x->canBeConquered(Territories.size()) == true) {
          /* generate secret number between 1 and 6: */
          int randNum = rand() % 6 + 1;
          if (randNum + empire->GetMilitaryForce() >= x->GetResistance()) {
            x->SetConquered(true);
            addEmpireTerritoryOwned(x);
            cout << x->Getname() << " Conquered!" << endl;
          } else {
            empire->SetMilitaryForce(empire->GetMilitaryForce() - 1);
            cout << "You lost the battle!\n"
                 << x->Getname() << " was not Conquered! You have now <"
                 << empire->GetMilitaryForce() << "> Military!" << endl;
          }
          return;
        } else {
          cout << "The territory that you want to conquer is an island. You "
                  "must have at least 5 territories to conquer an island!"
               << endl;
          return;
        }
      }
    }
  } else {
    cout << "You dont have enough Military Force to Conquer a territory. You "
            "need to have at least 1 military!"
         << endl;
    return;
  }
  cout << "No territory with that name!" << endl;
}

void World::conquerTerritoryDEBUG(const string t) {
  for (auto *x : Territories) {
    if (t.compare(x->Getname()) == 0) {
      if (x->GetConquered()) {
        cout << "This territory is already conquered!" << endl;
        return;
      }
      x->SetConquered(true);
      addEmpireTerritoryOwned(x);
      cout << x->Getname() << " Conquered!" << endl;
      return;
    }
  }
  cout << "No territory with that name!" << endl;
}

void World::conquerTechnology(const string t) {
  for (auto *x : Technologies) {
    if (t.compare(x->GetName()) == 0) {
      for (auto *y : empire->GetOwnedTechnologies()) {
        if (t.compare(y->GetName()) == 0) {
          cout << "You already have that Technology!" << endl << endl;
          return;
        }
      }
      if (empire->GetSafe() >= x->GetPrice()) {
        empire->SetSafe(empire->GetSafe() - x->GetPrice());
        x->activateTecnology(empire);
        x->SetIsAcquire(true);
        empire->addTechnology(x);
        cout << "You bought this technology: " << t << endl << endl;
        return;
      } else {
        cout << "You dont have money to buy this technology" << endl << endl;
        return;
      }
    }
  }
  cout << "No technology with that name!" << endl << endl;
}

void World::conquerTechnologyDEBUG(const string t) {
  for (auto *x : Technologies) {
    if (t.compare(x->GetName()) == 0) {
      for (auto *y : empire->GetOwnedTechnologies()) {
        if (t.compare(y->GetName()) == 0) {
          cout << "You already have that Technology!" << endl << endl;
          return;
        }
      }
      empire->SetSafe(empire->GetSafe() - x->GetPrice());
      x->activateTecnology(empire);
      x->SetIsAcquire(true);
      empire->addTechnology(x);
      cout << "You acquire this technology: " << t << endl << endl;
      return;
    }
  }
  cout << "No technology with that name!" << endl << endl;
}