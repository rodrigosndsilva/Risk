#ifndef __DEFENSES_H__
#define __DEFENSES_H__
#include "Technology.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Empire;

class Defenses : public Technology {
  std::string name;
  std::string description;

public:
  Defenses(std::string name, int price);
  ~Defenses();
  void activateTecnology(Empire *e) override;

  // gets e sets
  std::string GetDescription() const { return description; }
  std::string GetName() const { return name; }
};

#endif // __DEFENSES_H__