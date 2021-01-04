#ifndef __TECHNOLOGY_H__
#define __TECHNOLOGY_H__
#include "Empire.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Empire;

class Technology {
  std::string name;
  int price;
  bool isAcquire;
  std::string description;

public:
  Technology(std::string name, int price);
  virtual ~Technology();

  virtual void activateTecnology(Empire *e) = 0;
  std::string print() const;

  // gets e sets
  int GetPrice() const { return price; }
  void SetPrice(int price) { this->price = price; }
  virtual std::string GetName() const { return name; }
  bool GetIsAcquire() const { return isAcquire; }
  void SetIsAcquire(bool isAcquire) { this->isAcquire = isAcquire; }
  virtual std::string GetDescription() const { return description; };
};

#endif // __TECHNOLOGY_H__