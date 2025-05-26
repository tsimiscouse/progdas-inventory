/**
 * Project Class-Diagram-Progdas
 */


#ifndef _CONTROLLER_H
#define _CONTROLLER_H

class Controller {
public: 
    
void mainMenu();
    
void userMenu();
private: 
    AuthManager authManager;
    string currentUser;
    Inventory inventory;
};

#endif //_CONTROLLER_H