#ifndef __Mine_H__
#define __Mine_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Mine : public Territory {
  std::string name;
  static int cont;

public:
  Mine(std::string name, int resistance, int productCreation, int goldCreation,
        bool conquered, int victoryPoints);
  ~Mine();
  //std::string print() const;
  void updateTerritoryProduction(int turn);

  std::string Getname() const override { return name; } 
  void SetName(std::string name) { this->name = name; }
};

#endif // __Mine_H__