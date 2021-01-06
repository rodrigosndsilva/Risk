#ifndef __EMPIRE_H__
#define __EMPIRE_H__
#include "Technology.h"
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Territory;

class Empire {
  int safe;      // gold
  int warehouse; // products
  int maxSafe;
  int maxWarehouse;
  int militaryForce;
  int maxMilitaryForce;

  std::vector<Territory *> ownedTerritories;
  std::vector<Technology *> ownedTechnologies;

public:
  Empire();
  ~Empire();

  void addownedTerritory(Territory *t);
  void addTechnology(Technology *t);
  void removelastTerritory();
  std::string print() const;
  void collectGoldAndProductsFromTerritories();
  void buymilitary();

  // sets e gets
  int GetSafe() const { return safe; }
  void SetSafe(int safe) { this->safe = safe; }
  int GetWarehouse() const { return warehouse; }
  void SetWarehouse(int warehouse) { this->warehouse = warehouse; }
  int GetMaxSafe() const { return maxSafe; }
  void SetMaxSafe(int maxSafe) { this->maxSafe = maxSafe; }
  int GetMaxWarehouse() const { return maxWarehouse; }
  void SetMaxWarehouse(int maxWarehouse) { this->maxWarehouse = maxWarehouse; }
  int GetMilitaryForce() const { return militaryForce; }
  void SetMilitaryForce(int militaryForce) {
    this->militaryForce = militaryForce;
  }
  int GetMaxMilitaryForce() const { return maxMilitaryForce; }
  void SetMaxMilitaryForce(int maxMilitaryForce) {
    this->maxMilitaryForce = maxMilitaryForce;
  }
  std::vector<Territory *> GetOwnedTerritories() const {
    return ownedTerritories;
  }
  std::vector<Technology *> GetOwnedTechnologies() const {
    return ownedTechnologies;
  }
};

#endif // __EMPIRE_H__