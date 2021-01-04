#include "../include/Territory.h"
using namespace std;

Territory::Territory(string name, int resistance, int productCreation,
                     int goldCreation, bool conquered, int victoryPoints) {
  this->name = name;
  this->resistance = resistance;
  this->productCreation = productCreation;
  this->goldCreation = goldCreation;
  this->conquered = conquered;
  this->victoryPoints = victoryPoints;

  // cout << "Your " << Getname() << " is Created on base!\n";
}

Territory::~Territory() { cout << Getname() << " Deleted on base!" << endl; }

string Territory::print() const {
  ostringstream os;
  os << "Name: " << Getname() << "\tResistance: " << resistance
     << "\tProduct Creation: " << productCreation
     << "\tGold Creation: " << goldCreation << "\tConquered: " << conquered
     << "\tVictory Points: " << victoryPoints << endl;
  return os.str();
}

void Territory::updateTerritoryProduction(int turn) {
  if (turn > 0) {
    SetProductCreation(GetProductCreation());
  }
  if (turn > 0) {
    SetGoldCreation(GetGoldCreation());
  }
}

bool Territory::canBeConquered(Empire *e) {
  if (e->GetOwnedTerritories().size() >= 1)
    return true;
  return false;
}