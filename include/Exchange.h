#ifndef __EXCHANGE_H__
#define __EXCHANGE_H__
#include "Technology.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Empire;

class Exchange : public Technology {
  std::string name;
  std::string description;

public:
  Exchange(std::string name, int price);
  ~Exchange();
  void activateTecnology(Empire *e) override;

  // gets e sets
  std::string GetDescription() const { return description; }
  std::string GetName() const { return name; }
};

#endif // __EXCHANGE_H__