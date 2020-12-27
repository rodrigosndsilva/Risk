#ifndef __Castle_H__
#define __Castle_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Castle : public Territory {
  std::string name;
  static int cont;

public:
  Castle(std::string name, int resistance, int productCreation,
         int goldCreation, bool conquered, int victoryPoints);
  ~Castle();
  // std::string print() const;
  void updateTerritoryProduction(int turn) override;

  std::string Getname() const override { return name; }
  void SetName(std::string name) { this->name = name; }
};

#endif // __Castle_H__