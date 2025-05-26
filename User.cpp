#include "User.h"

User::User() : username(""), password("") {}

User::User(const string& username, const string& password) 
    : username(username), password(password) {}

string User::getUsername() const { return username; }
string User::getPassword() const { return password; }
