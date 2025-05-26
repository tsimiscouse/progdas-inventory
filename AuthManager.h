#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "User.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class AuthManager {
private:
    vector<User> users;
    void loadUsers();
    void saveUser(const User& user);

public:
    AuthManager();
    bool registerUser();
    bool login(string& currentUser);
};

#endif
