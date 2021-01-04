#ifndef __TERRITORY_H__
#define __TERRITORY_H__
#include "Empire.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Empire;

class Territory {
  std::string name;
  int resistance;
  int productCreation;
  int goldCreation;
  bool conquered;
  int victoryPoints;

public:
  Territory(std::string name, int resistance, int productCreation,
            int goldCreation, bool conquered, int victoryPoints);
  virtual ~Territory();

  virtual std::string print() const;
  virtual void updateTerritoryProduction(int turn);
  virtual bool canBeConquered(Empire *e);

  // gets and sets
  virtual std::string Getname() const { return name; }
  int GetResistance() const { return resistance; }
  void SetResistance(int resistance) { this->resistance = resistance; }
  virtual int GetProductCreation() const { return productCreation; }
  void SetProductCreation(int productCreation) {
    this->productCreation = productCreation;
  }
  virtual int GetGoldCreation() const { return goldCreation; }
  void SetGoldCreation(int goldCreation) { this->goldCreation = goldCreation; }
  bool GetConquered() const { return conquered; }
  void SetConquered(bool conquered) { this->conquered = conquered; }
  int GetVictoryPoints() const { return victoryPoints; }
  void SetVictoryPoints(int victoryPoints) {
    this->victoryPoints = victoryPoints;
  }
};

#endif // __TERRITORY_H__