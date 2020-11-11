#ifndef __WORLD_H__
#define __WORLD_H__
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Home.h"
#include "Territories.h"

class World {
    Territories *territories;
public:
  World();
  ~World();
  std::string print() const;
};

#endif // __WORLD_H__