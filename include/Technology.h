#ifndef __TECHNOLOGY_H__
#define __TECHNOLOGY_H__
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Empire.h"

class Technology {
  int price;

public:
  Technology(int price);
  ~Technology();

  void buyTecnology();

  // gets e sets
  int GetPrice() const { return price; }
  void SetPrice(int price) { this->price = price; }
};

#endif // __TECHNOLOGY_H__