#ifndef __TERRITORIES_H__
#define __TERRITORIES_H__
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Home.h"

class Territories {
  Home *home;

public:
  Territories();
  ~Territories();

  std::string print() const;
  Home *GetHome() const { return home; }
  void SetHome(Home home) { home = home; }
};

#endif // __TERRITORIES_H__