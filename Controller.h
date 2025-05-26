#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Inventory.h"
#include "AuthManager.h"
#include <string>
using std::string;

class Controller {
private:
    string currentUser;
    Inventory* inventory;
    AuthManager authManager;

    void mainMenu();
    void userMenu();

public:
    Controller();
    ~Controller();
    void run();
};

#endif
