#ifndef __Dune_H__
#define __Dune_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Dune : public Territory {
  std::string name;
  static int cont;

public:
  Dune(std::string name, int resistance, int productCreation, int goldCreation,
        bool conquered, int victoryPoints);
  ~Dune();
  //std::string print() const;

  std::string Getname() const override { return name; } 
  void SetName(std::string name) { this->name = name; }
};

#endif // __Dune_H__