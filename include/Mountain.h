#ifndef __MOUNTAIN_H__
#define __MOUNTAIN_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Mountain : public Territory {
  std::string name;
  static int cont;
  int contProductions;

public:
  Mountain(std::string name, int resistance, int productCreation,
           int goldCreation, bool conquered, int victoryPoints);
  ~Mountain();
  //std::string print() const;
  void updateTerritoryProduction(int turn);

  std::string Getname() const override { return name; }
  void SetName(std::string name) { this->name = name; }
  void updateTerritoryProduction();
  int GetContProductions() const { return contProductions; }
  void SetContProductions(int contProductions) {
    this->contProductions = contProductions;
  }
};

#endif // __MOUNTAIN_H__