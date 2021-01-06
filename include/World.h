#ifndef __WORLD_H__
#define __WORLD_H__
#include "AbandonatedResource.h"
#include "Alliance.h"
#include "Bank.h"
#include "Castle.h"
#include "Defenses.h"
#include "Drones.h"
#include "Dune.h"
#include "Empire.h"
#include "Event.h"
#include "Fishing.h"
#include "Fortress.h"
#include "Invasion.h"
#include "Mine.h"
#include "Missiles.h"
#include "Mountain.h"
#include "Plain.h"
#include "Refuge.h"
#include "Technology.h"
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class World {
  std::vector<Territory *> Territories;
  std::vector<Technology *> Technologies;
  std::vector<Event *> Events;

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
  void conquerTechnologyDEBUG(const std::string t);
  void conquerTechnology(const std::string t);
  void createAnEvent(int turn);

  // gets and sets
  Empire *GetEmpire() const { return empire; }
  void SetEmpire(Empire *empire) { empire = empire; }
  std::vector<Event *> GetEvents() const { return Events; }
  std::vector<Territory *> GetTerritories() const { return Territories; }
};

#endif // __WORLD_H__