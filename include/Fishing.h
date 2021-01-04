#ifndef __FISHING_H__
#define __FISHING_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Fishing : public Territory {
  std::string name;
  static int cont;

public:
  Fishing(std::string name, int resistance, int productCreation,
          int goldCreation, bool conquered, int victoryPoints);
  ~Fishing();
  // std::string print() const;
  bool canBeConquered(Empire *e);
  void updateTerritoryProduction(int turn);

  // gets e sets
  std::string Getname() const override { return name; }
  void SetName(std::string name) { this->name = name; }
};

#endif // __FISHING_H__