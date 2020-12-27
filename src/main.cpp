// g++ -std=c++14 -Wall -Wextra -g *.cpp -o main

#include "../include/Interaction.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cout << "\n\n";
  World *w = new World();
  Interaction i(w);
  int flag = i.setupGame();
  if (flag != 2) {
    i.handlegame();
  }
  cout << "\n";
  return 0;
}