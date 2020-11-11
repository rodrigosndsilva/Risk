#ifndef __HOME_H__
#define __HOME_H__
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Home {
  std::string name;
  int resistance;
  int productCreation;
  int goldCreation;
  bool conquered;
  int victoryPoints;

public:
  Home();
  ~Home();
  std::string print() const;

  // gets and sets
  std::string Getname() const { return name; }
  void Setname(std::string name) { this->name = name; }
  int GetResistance() const { return resistance; }
  void SetResistance(int resistance) { this->resistance = resistance; }
  int GetProductCreation() const { return productCreation; }
  void SetProductCreation(int productCreation) {
    this->productCreation = productCreation;
  }
  int GetGoldCreation() const { return goldCreation; }
  void SetGoldCreation(int goldCreation) { this->goldCreation = goldCreation; }
  bool GetConquered() const { return conquered; }
  void SetConquered(bool conquered) { this->conquered = conquered; }
  int GetVictoryPoints() const { return victoryPoints; }
  void SetVictoryPoints(int victoryPoints) {
    this->victoryPoints = victoryPoints;
  }
};

#endif // __HOME_H__