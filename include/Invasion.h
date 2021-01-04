#ifndef __INVASION_H__
#define __INVASION_H__
#include "Event.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Event;

class Invasion : public Event {
  std::string name;
  int num;

public:
  Invasion(std::string name, int num);
  ~Invasion();
  void activateEvent(Empire *e, int turn) override;

  // gets e sets
  std::string GetName() const { return name; }
  int GetNum() const override { return num; }
};

#endif // __INVASION_H__