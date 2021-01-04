#ifndef __DRONES_H__
#define __DRONES_H__
#include "Technology.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Empire;

class Drones : public Technology {
  std::string name;
  std::string description;

public:
  Drones(std::string name, int price);
  ~Drones();
  void activateTecnology(Empire *e) override;

  // gets e sets
  std::string GetDescription() const { return description; }
  std::string GetName() const { return name; }
};

#endif // __DRONES_H__