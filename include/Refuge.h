#ifndef __REFUGE_H__
#define __REFUGE_H__
#include "Territory.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Refuge : public Territory {
  std::string name;
  static int cont;

public:
  Refuge(std::string name, int resistance, int productCreation,
               int goldCreation, bool conquered, int victoryPoints);
  ~Refuge();
  // std::string print() const;
  bool canBeConquered(int numTerr);

  // gets e sets
  std::string Getname() const override { return name; }
  void SetName(std::string name) { this->name = name; }
};

#endif // __REFUGE_H__