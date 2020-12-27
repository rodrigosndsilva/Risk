#ifndef __WORLD_H__
#define __WORLD_H__
#include "Castle.h"
#include "Dune.h"
#include "Empire.h"
#include "Fortress.h"
#include "Mine.h"
#include "Mountain.h"
#include "Fishing.h"
#include "Refuge.h"
#include "Plain.h"
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class World {
  std::vector<Territory *> Territories;
  Empire *empire;

public:
  World(const World &w) = delete;
  World();
  ~World();
  void print() const;
  void updateAllTerritoriesProductions(int turn);
  void addTerritory(Territory *t);
  void addEmpireTerritoryOwned(Territory *t);
  void conquerTerritory(const std::string t);
  void conquerTerritoryDEBUG(const std::string t);

  // gets and sets
  Empire *GetEmpire() const { return empire; }
  void SetEmpire(Empire *empire) { empire = empire; }
};

#endif // __WORLD_H__