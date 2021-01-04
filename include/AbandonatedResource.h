#ifndef __ABANDONATEDRESOURCE_H__
#define __ABANDONATEDRESOURCE_H__
#include "Event.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Event;

class AbandonatedResource : public Event {
  std::string name;
  int num;

public:
  AbandonatedResource(std::string name, int num);
  ~AbandonatedResource();
  void activateEvent(Empire *e, int turn) override;

  // gets e sets
  std::string GetName() const { return name; }
  int GetNum() const override { return num; }
};

#endif // __ABANDONATEDRESOURCE_H__