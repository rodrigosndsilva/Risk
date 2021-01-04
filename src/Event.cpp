#include "../include/Event.h"
using namespace std;

Event::Event(string name, int num) {
  this->name = name;
  this->num = num;
}

Event::~Event() { cout << GetName() << " Deleted on base!" << endl; }