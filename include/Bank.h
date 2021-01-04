#ifndef __BANK_H__
#define __BANK_H__
#include "Technology.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Technology;
class Empire;

class Bank : public Technology {
  std::string name;
  std::string description;

public:
  Bank(std::string name, int price);
  ~Bank();
  void activateTecnology(Empire *e) override;

  // gets e sets
  std::string GetDescription() const { return description; }
  std::string GetName() const { return name; }
};

#endif // __BANK_H__