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

  World *world;

  std::vector<std::string> runcommands;
  std::vector<World *> saveWorlds;

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
  std::vector<std::string> splitSentenceIntoWords(std::string c);
  void winGame();
  int loseGame();
  void saveWorld(std::string name);

  // gets e sets
  World *GetWorld() const { return world; }
};

#endif // __INTERACTION_H__