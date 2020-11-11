#include "../include/Home.h"
using namespace std;

Home::Home() {
  this->name = "Home";
  this->resistance = 9;
  this->productCreation = 1;
  this->goldCreation = 1;
  this->conquered = false;
  this->victoryPoints = 0;
  cout << "Creating your Home :D\n" << print();
}

Home::~Home() {cout << "Deleting your Home :D\n " << print();}

std::string Home::print() const {
  ostringstream os;
  os << "Name: " << name << "\tResistance: " << resistance
     << "\tProduct Creation: " << productCreation
     << "\tGold Creation: " << goldCreation << "\tConquered: " << conquered
     << "\tVictory Points: " << victoryPoints << endl;
  return os.str();
}
