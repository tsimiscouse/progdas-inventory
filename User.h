#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
private:
    string username;
    string password;

public:
    User();
    User(const string& username, const string& password);

    string getUsername() const;
    string getPassword() const;
};

#endif
