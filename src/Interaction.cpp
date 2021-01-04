#include "../include/Interaction.h"
using namespace std;

Interaction::Interaction(World *world) {
  this->world = world;
  turn = 0;
  cout << "Interaction Created \n " << endl;
}

Interaction::~Interaction() {
  delete (world);
  cout << "Interaction Deleted \n " << endl;
}

void Interaction::runAllCommands() {
  for (string x : runcommands) {
    int flag = handleCommand(x);
    if (flag == 0) {
      cout << "Command not found!" << endl;
    }
  }
}

int Interaction::setupGame() {
  cout << "\n\nConfiguration of the game!\nType <help> to see the commands. "
          "<endsetup> to proceed!"
       << endl;
  int flag = 0;
  string command;
  do {
    getline(cin, command);
    cout << endl;
    if (command != "endsetup") {
      flag = handleCommand(command);
      if (flag == 0) {
        cout << "Command not found!" << endl;
      }
      if (flag == 2)
        return flag;
    }
  } while (command != "quit" && command != "endsetup");
  turn++;
  return flag;
}

void Interaction::handlegame() {
  int flagmilitar = 0, flagtecnology = 0;

  cout << "\n\nGame initiated" << endl;
  string command;
  world->GetEmpire()->collectGoldAndProductsFromTerritories();

  do {
    world->updateAllTerritoriesProductions(GetTurn());
    print();
    do {
      cout << "Conquer a territorry or pass: ";
      getline(cin, command);
      if (command == "help") {
        handleCommand(command);
      }
    } while (command == "help");

    if (command == "quit")
      return;
    runcommands.push_back(command);

    do {
      cout << "Do you want to buy a technology or a military? (yes/no): ";
      getline(cin, command);
      if (command == "help") {
        handleCommand(command);
      }
    } while (command == "help");
    if (command == "quit")
      return;

    if (command == "yes") {
      flagmilitar = 0, flagtecnology = 0;
      do {
        cout << "Buy a tecnology or a military (to proceed type endbuy): ";
        getline(cin, command);
        if (command == "quit")
          return;
        if (command != "endbuy") {
          if (command != "help") {
            istringstream iss(command);
            vector<string> commands;
            if (command != "") {
              for (string arg; iss >> arg;) {
                commands.push_back(arg);
              }
            }
            if ((flagmilitar == 1 && command == "moremilitary") ||
                (flagtecnology == 1 && commands[0] == "acquire")) {
              cout << "You have already purchage one time the <" << command
                   << "> option" << endl;
            } else {
              if (flagmilitar == 0 && command == "moremilitary") {
                runcommands.push_back(command);
                flagmilitar = 1;
              }
              if (flagtecnology == 0 && commands[0] == "acquire") {
                runcommands.push_back(command);
                flagtecnology = 1;
              }
            }
          } else {
            handleCommand(command);
          }
        }
      } while (command != "endbuy");
    }

    do {
      cout << "Debug time (type <next> to jump to turn-> " << turn + 1 << "): ";
      getline(cin, command);
      cout << endl;
      if (command == "next")
        runcommands.push_back(command);
      else
        handleCommand(command);
    } while (command != "quit" && command != "next");
    runAllCommands();
  } while (command != "quit");
}

int Interaction::handleCommand(string c) {
  istringstream iss(c);
  vector<string> command;
  if (c == "") {
    return 0;
  }
  for (string arg; iss >> arg;) {
    command.push_back(arg);
  }

  if (command[0] == "quit") {
    return 2;
  }
  if (command[0] == "help" && turn == 0) {
    cout << "\n\nCommands for the configurations:\n\nload <File-Name>\ncreate "
            "<type> <n>\ntake <terr/tec> <name>\nendsetup -> To complete Game "
            "setup.\n\n";
    return 1;
  }
  if (command[0] == "help" && turn > 0) {
    cout << "\n\nCommands for the game:\n\nlistall\nlist "
            "<name>\npass\nmoreproduct\nmoregold\nmoremilitary\nacquire "
            "<type>\nsave <name>\nloadgame <name>\ndeletegame "
            "<name>\nnext\n\nDebug commands:\ntake <terr/tec> <name>\nmodify <gold|prod> N\nevent "
            "<name-of-event>\n\n";
    return 1;
  }
  if (command[0] == "pass" && turn > 0) {
    cout << "You chose the pass option, that is, no territory was conquered "
            "this turn!"
         << endl;
    return 1;
  }
  if (command[0] == "next" && turn > 0) {
    world->GetEmpire()->collectGoldAndProductsFromTerritories();
    runcommands.clear();
    cout << "----> Turn " << turn << " over! <----" << endl << endl;
    turn++;
    return 1;
  }
  if (command[0] == "create") {
    if (command.size() != 3) {
      return 0;
    }
    if (command[1] != "plain" && command[1] != "mountain" &&
        command[1] != "fortress" && command[1] != "mine" &&
        command[1] != "dune" && command[1] != "castle" &&
        command[1] != "refuge" && command[1] != "fishing")
      return 0;

    for (int i = 0; i < stoi(command[2]); i++) {
      if (command[1] == "plain") {
        world->addTerritory(new Plain("Plain", 5, 1, 1, false, 1));
      }
      if (command[1] == "mountain") {
        world->addTerritory(new Mountain("Mountain", 6, 1, 0, false, 1));
      }
      if (command[1] == "fortress") {
        world->addTerritory(new Fortress("Fortress", 8, 0, 0, false, 1));
      }
      if (command[1] == "mine") {
        world->addTerritory(new Mine("Mine", 5, 0, 1, false, 1));
      }
      if (command[1] == "dune") {
        world->addTerritory(new Dune("Dune", 4, 1, 0, false, 1));
      }
      if (command[1] == "castle") {
        world->addTerritory(new Castle("Castle", 7, 3, 1, false, 1));
      }
      if (command[1] == "refuge") {
        world->addTerritory(new Refuge("Refuge", 9, 0, 1, false, 2));
      }
      if (command[1] == "fishing") {
        world->addTerritory(new Fishing("Fishing", 9, 2, 0, false, 2));
      }
    }
    return 1;
  }
  if (command[0] == "conquer" && turn > 0) {
    if (command.size() != 2) {
      return 0;
    }
    world->conquerTerritory(command[1]);
    return 1;
  }
  if (command[0] == "take") {
    if (command.size() != 3) {
      return 0;
    }
    if (command[1] == "terr") {
      world->conquerTerritoryDEBUG(command[2]);
    }

    if (command[1] == "tec") {
      world->conquerTechnologyDEBUG(command[2]);
    }

    return 1;
  }
  if (command[0] == "moremilitary" && turn > 0) {
    world->GetEmpire()->buymilitary();
    return 1;
  }
  if (command[0] == "listall") {
    world->print();
    return 1;
  }
  if (command[0] == "load" && turn == 0) {
    if (command.size() != 2) {
      return 0;
    }
    if (loadFile(command[1]) == 2) {
      return 2;
    }
    return 1;
  }
  return 0;
}

int Interaction::loadFile(string name) {
  ifstream filei("../include/" + name);
  string line;

  if (filei.is_open()) {
    while (getline(filei, line)) {
      int flag = handleCommand(line);
      if (flag == 0) {
        cout << "Command not found!" << endl;
      }
      if (flag == 2) {
        return 2;
      }
    }
  } else
    cerr << "Erro a abrir ficheiro\n";
  return 1;
}

void Interaction::print() const {
  cout << "\nTurn: " << turn;
  world->print();
  cout << "Type <help> to see all commands.\n" << endl;
}