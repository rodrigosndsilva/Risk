#ifndef __INTERACTION_H__
#define __INTERACTION_H__
#include "World.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
class Interaction {
  int turn;
  int year;

  std::vector<std::string> runcommands;
  World *world;

public:
  Interaction(World *world);
  Interaction();
  ~Interaction();
  void print() const;
  void handlegame();
  void commands();
  int handleCommand(std::string command);
  int loadFile(std::string name);
  int setupGame();
  void runAllCommands();

  // gets e sets
  int GetTurn() { return turn; }
  World *GetWorld() const { return world; }
  int GetYear() const { return year; }
  void SetYear(int year) { this->year = year; }
};

#endif // __INTERACTION_H__