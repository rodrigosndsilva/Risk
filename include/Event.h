#ifndef __EVENT_H__
#define __EVENT_H__
#include "Empire.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Empire;

class Event {
  std::string name;
  int num;

public:
  Event(std::string name, int num);
  ~Event();
  virtual void activateEvent(Empire *e, int turn) = 0;

  // gets e sets
  std::string GetName() const { return name; }
  virtual int GetNum() const { return num; }
};

#endif // __EVENT_H__