#ifndef __PLAIN_H__
#define __PLAIN_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Plain : public Territory {
  std::string name;
  static int cont;

public:
  Plain(std::string name, int resistance, int productCreation, int goldCreation,
        bool conquered, int victoryPoints);
  ~Plain();
  // std::string print() const;
  void updateTerritoryProduction(int turn) override;
  
  // gets e sets
  std::string Getname() const override { return name; }
  void SetName(std::string name) { this->name = name; }
};

#endif // __PLAIN_H__