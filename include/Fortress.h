#ifndef __Fortress_H__
#define __Fortress_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Fortress : public Territory {
  std::string name;
  static int cont;

public:
  Fortress(std::string name, int resistance, int productCreation, int goldCreation,
        bool conquered, int victoryPoints);
  ~Fortress();
  //std::string print() const;

  std::string Getname() const override { return name; } 
  void SetName(std::string name) { this->name = name; }
};

#endif // __Fortress_H__