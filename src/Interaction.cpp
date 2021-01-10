#include "../include/Interaction.h"
using namespace std;

Interaction::Interaction(World *world) {
  this->world = world;
  saveWorlds.push_back(world);
  cout << "Interaction Created \n " << endl;
}

Interaction::~Interaction() {
  for (auto *x : saveWorlds)
    delete x;
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
  world->SetTurn(world->GetTurn() + 1);
  return flag;
}

vector<string> Interaction::splitSentenceIntoWords(string c) {
  istringstream iss(c);
  vector<string> commands;
  if (c != "") {
    for (string arg; iss >> arg;) {
      commands.push_back(arg);
    }
  }
  return commands;
}

void Interaction::handlegame() {
  string command;
  vector<string> commands;
  int flagmilitar = 0, flagtecnology = 0, flag = 0;

  cout << "\n\nGame initiated" << endl;

  // Fase 1
  do {
    flag = 0;

    world->updateAllTerritoriesProductions();
    world->GetEmpire()->collectGoldAndProductsFromTerritories();

    print();
    do {
      cout << "Fase 1 -> Conquer a territorry or pass: ";
      getline(cin, command);
      if (command == "quit")
        return;
      if (command != "") {
        commands = splitSentenceIntoWords(command);
      }
      if (command == "help" || command == "listall") {
        handleCommand(command);
      }
      if (commands[0] == "conquer" || command == "pass")
        flag = 1;
    } while (command == "help" || command == "listall" || flag == 0);

    runcommands.push_back(command);
    flag = 0;

    // Fase 2
    for (auto *x : world->GetEmpire()->GetOwnedTechnologies()) {
      if (x->GetName() == "Exchange") {
        do {
          cout << "Fase 2 -> Do you want to trade gold or products? "
                  "(yes/no): ";
          getline(cin, command);
          if (command == "quit")
            return;
          if (command != "") {
            commands = splitSentenceIntoWords(command);
          }
          if (command == "help" || command == "listall") {
            handleCommand(command);
          }
          if (command == "yes" || command == "no")
            flag = 1;

        } while (command == "help" || command == "listall" || flag == 0);

        if (command == "yes") {
          do {
            cout << "Trade gold for products or vice versa (moregold "
                    "/ "
                    "moreproduct): ";
            getline(cin, command);
            if (command == "quit")
              return;
            if (command == "moregold" || command == "moreproduct") {
              handleCommand(command);
              flag = 1;
            }
          } while (command == "help" || command == "listall" || flag == 0);
          break;
        }
      }
    }
    if (flag != 1) {
      cout << "Fase 2 -> You dont have de Exchange technology, so you can not "
              "trade gold/products!"
           << endl;
    }
    flag = 0;

    // Fase 3
    do {
      cout << "Fase 3 -> Do you want to buy a technology or a military? "
              "(yes/no): ";
      getline(cin, command);
      if (command == "quit")
        return;
      if (command != "") {
        commands = splitSentenceIntoWords(command);
      }
      if (command == "help" || command == "listall") {
        handleCommand(command);
      }
      if (command == "yes" || command == "no")
        flag = 1;

    } while (command == "help" || command == "listall" || flag == 0);

    if (command == "yes") {
      flagmilitar = 0, flagtecnology = 0;
      do {
        cout << "Buy a tecnology or a military (to proceed type endbuy): ";
        getline(cin, command);
        if (command == "quit")
          return;
        if (command != "endbuy") {
          if (command != "help" || command != "listall") {
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
            if (command != "")
              handleCommand(command);
          }
        }
      } while (command != "endbuy");
    }

    // Fase 4
    cout << "\nFase 4 -> Random Event: " << endl;
    world->createAnEvent(world->GetTurn());

    // Debug Fase
    do {
      cout << "Debug time (type <next> to jump to turn-> "
           << world->GetTurn() + 1 << "): ";
      getline(cin, command);
      if (command == "quit")
        return;
      cout << endl;

      if (command == "next")
        runcommands.push_back(command);
      else {
        if (command != "")
          flag = handleCommand(command);
      }
      if (flag == 0) {
        cout << "Command not found!" << endl;
      }

      if (flag == 2)
        return;

    } while (command != "quit" && command != "next");
    runAllCommands();
    if (world->GetTurn() == 13)
      break;
  } while (command != "quit");
  if (world->GetTurn() > 12)
    winGame();
}

void Interaction::winGame() {
  int contTec = 0, sumterr = 0, sumtec = 0, sumAll = 0;
  unsigned int contTerr = 0;

  cout << "\n\n---> Game Ended <---" << endl << endl;
  cout << "---> Territories Conquered <---" << endl;
  for (auto *x : world->GetEmpire()->GetOwnedTerritories()) {
    cout << " -> " << x->Getname()
         << "\tVictory Points: " << x->GetVictoryPoints() << endl;
    sumterr += x->GetVictoryPoints();
    contTerr++;
  }
  cout << "\n---> Technologies Conquered <---" << endl;
  for (auto *y : world->GetEmpire()->GetOwnedTechnologies()) {
    cout << " -> " << y->GetName() << "\tVictory Points: 1" << endl;
    sumtec += 1;
    contTec++;
  }
  sumAll = sumtec + sumterr;
  cout << "\n---> Final score <---" << endl << endl;
  cout << sumterr << "+ -> sum of victory points for all Territories." << endl;
  cout << sumtec << "+ -> sum of victory points for all Technologies." << endl;
  if (contTec == 5) {
    cout << "1+ -> 5 technologies acquired (scientific bonus)." << endl;
    sumAll += 1;
  }

  if (contTerr == world->GetTerritories().size()) {
    cout << "3+ -> you have all terrains ( " << contTerr
         << " territories) in the world are part of the empire (supreme "
            "emperor). "
         << endl;
    sumAll += 3;
  }
  cout << endl << sumAll << " -> Final Score!" << endl;
}

int Interaction::loseGame() {
  cout << "\n\n---> You lost the game <---" << endl;
  cout << "Your last territory was defeated <SafeHouse>" << endl;
  cout << "Game Ended!" << endl << endl;
  return 2;
}

int Interaction::handleCommand(string c) {
  vector<string> command;
  command = splitSentenceIntoWords(c);

  if (command[0] == "quit") {
    return 2;
  }
  if (command[0] == "help" && world->GetTurn() == 0) {
    cout << "\n\nCommands for the configurations:\n\nload <File-Name>\ncreate "
            "<type> <n>\ntake <terr/tec> <name>\nendsetup -> To complete Game "
            "setup.\n\n";
    return 1;
  }
  if (command[0] == "help" && world->GetTurn() > 0) {
    cout << "\n\nCommands for the game:\n\nlistall\nlist "
            "<name>\npass\nmoreproduct\nmoregold\nmoremilitary\nacquire "
            "<type>\nsave <name>\nloadgame <name>\ndeletegame "
            "<name>\nnext\n\nDebug commands:\ntake <terr/tec> <name>\nmodify "
            "<gold|prod> N\ncreate "
            "<type>\nfevent "
            "<name-of-event>\njumpturn <turn_number>\n\n";
    return 1;
  }

  if (command[0] == "listall") {
    print();
    return 1;
  }
  if (command[0] == "list") {
    if (command.size() != 2) {
      return 0;
    }
    for (auto *x : world->GetTerritories()) {
      if (x->Getname() == command[1]) {
        cout << x->print() << endl;
      }
    }
    return 1;
  }

  // setup commands
  if (command[0] == "load") {
    if (command.size() != 2) {
      return 0;
    }
    if (loadFile(command[1]) == 2) {
      return 2;
    }
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

  // game commands
  if (command[0] == "conquer" && world->GetTurn() > 0) {
    if (command.size() != 2) {
      return 0;
    }
    world->conquerTerritory(command[1]);
    return 1;
  }

  if (command[0] == "pass" && world->GetTurn() > 0) {
    cout << "You chose the pass option, that is, no territory was conquered "
            "this turn!"
         << endl;
    return 1;
  }
  if (command[0] == "next" && world->GetTurn() > 0) {
    runcommands.clear();
    cout << "----> Turn " << world->GetTurn() << " over! <----" << endl << endl;
    world->SetTurn(world->GetTurn() + 1);
    if (world->GetTurn() > 6)
      world->SetYear(2);
    return 1;
  }

  if (command[0] == "moremilitary" && world->GetTurn() > 0) {
    world->GetEmpire()->buymilitary();
    return 1;
  }

  if (command[0] == "moregold" && world->GetTurn() > 0) {
    if (world->GetEmpire()->GetWarehouse() >= 2) {
      world->GetEmpire()->SetWarehouse(world->GetEmpire()->GetWarehouse() - 2);
      if (world->GetEmpire()->GetSafe() < world->GetEmpire()->GetMaxSafe())
        world->GetEmpire()->SetSafe(world->GetEmpire()->GetSafe() + 1);
      cout << "You traded 2 products for 1 more gold!" << endl << endl;
    }
    return 1;
  }

  if (command[0] == "moreprod" && world->GetTurn() > 0) {
    if (world->GetEmpire()->GetSafe() >= 2) {
      world->GetEmpire()->SetSafe(world->GetEmpire()->GetSafe() - 2);
      if (world->GetEmpire()->GetWarehouse() <
          world->GetEmpire()->GetMaxWarehouse())
        world->GetEmpire()->SetWarehouse(world->GetEmpire()->GetWarehouse() +
                                         1);
      cout << "You traded 2 golds for 1 more product!" << endl << endl;
    }
    return 1;
  }

  // debug Commands
  if (command[0] == "jumpturn" && world->GetTurn() > 0) {
    if (command.size() != 2) {
      return 0;
    }
    world->SetTurn(stoi(command[1]));
    if (stoi(command[1]) <= 6) {
      world->SetYear(1);
    } else {
      world->SetYear(2);
    }
    return 1;
  }

  if (command[0] == "modify") {
    if (command.size() != 3) {
      return 0;
    }
    if (command[1] == "gold") {
      if ((stoi(command[2]) <= world->GetEmpire()->GetMaxSafe()) &&
          (stoi(command[2]) >= 0)) {
        world->GetEmpire()->SetSafe(stoi(command[2]));
        cout << "You modify you gold to: " << stoi(command[2]) << endl << endl;
      }
    }

    if (command[1] == "prod") {
      if ((stoi(command[2]) <= world->GetEmpire()->GetMaxWarehouse()) &&
          (stoi(command[2]) >= 0)) {
        world->GetEmpire()->SetWarehouse(stoi(command[2]));
        cout << "You modify you products to: " << stoi(command[2]) << endl
             << endl;
      }
    }

    return 1;
  }

  if (command[0] == "fevent" && world->GetTurn() > 0) {
    if (command.size() != 2) {
      return 0;
    }
    for (auto *x : world->GetEvents()) {
      if (x->GetName() == command[1]) {
        x->activateEvent(world->GetEmpire(), world->GetTurn());
        cout << "Event was forced successfully!" << endl << endl;
        if (world->GetEmpire()->GetOwnedTerritories().size() == 0) {
          loseGame();
          return 2;
        }
        return 1;
      }
    }
    cout << "No Event with that name!" << endl << endl;
    return 1;
  }

  if (command[0] == "acquire" && world->GetTurn() > 0) {
    if (command.size() != 2) {
      return 0;
    }
    world->conquerTechnology(command[1]);
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
  if (command[0] == "save") {
    if (command.size() != 2) {
      return 0;
    }
    saveWorld(command[1]);
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
  cout << "\nYear: " << world->GetYear() << "\t\t\tTurn: " << world->GetTurn()
       << endl
       << endl;
  cout << "Save Worlds:" << endl;
  for (auto *x : saveWorlds) {
    cout << x->GetName() << endl;
  }
  world->print();
  cout << "Type <help> to see all commands.\n" << endl;
}

void Interaction::saveWorld(string name) {
  saveWorlds.push_back(new World(*world, name));
}