#include "../include/World.h"
using namespace std;

World::World() {
  this->territories = new Territories();
  cout << "Creating World\n " << endl;
}

World::~World() {
  cout << "Deleting World\n " << endl;
  delete (territories);
}

std::string World::print() const {
  ostringstream os;
  os << "sadas "<< territories->print();
  return os.str();
}
