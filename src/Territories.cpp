#include "../include/Territories.h"
using namespace std;

Territories::Territories() {
  this->home = new Home();
  cout << "Created Territories\n " << endl;
}

Territories::~Territories() {
  cout << "Deleting Territories\n " << endl;
  delete (home);
}

std::string Territories::print() const {
  ostringstream os;
  os << home->print();
  return os.str();
}