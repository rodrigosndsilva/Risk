#ifndef __MISSILES_H__
#define __MISSILES_H__
#include "Technology.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Empire;

class Missiles : public Technology {
  std::string name;
  std::string description;

public:
  Missiles(std::string name, int price);
  ~Missiles();
  void activateTecnology(Empire *e) override;

  // gets e sets
  std::string GetDescription() const { return description; }
  std::string GetName() const { return name; }
};

#endif // __MISSILES_H__