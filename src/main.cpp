// g++ -std=c++14 -Wall -Wextra -g *.cpp -o main

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/World.h"
using namespace std;

int main() { 
	World *world = new World();
	cin.get();
	world->print();

	delete(world);
	return 0;
}