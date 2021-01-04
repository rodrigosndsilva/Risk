#ifndef __ALLIANCE_H__
#define __ALLIANCE_H__
#include "Event.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Event;

class Alliance : public Event {
  std::string name;
  int num;

public:
  Alliance(std::string name, int num);
  ~Alliance();
  void activateEvent(Empire *e, int turn) override;

  // gets e sets
  std::string GetName() const { return name; }
  int GetNum() const override { return num; }
};

#endif // __ALLIANCE_H__