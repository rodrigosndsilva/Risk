#include "../include/Drones.h"
using namespace std;

Drones::Drones(int price) : Technology(price) {
  cout << "Drone Tecnology Created!" << endl;
}

Drones::~Drones() { cout << "Drone Tecnology Deleted!" << endl; }

