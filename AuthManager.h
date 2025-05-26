/**
 * Project Class-Diagram-Progdas
 */


#ifndef _AUTHMANAGER_H
#define _AUTHMANAGER_H

class AuthManager {
public: 
    
void registerUser();
    
/**
 * @param currentUser
 */
bool login(string& currentUser);
private: 
    
/**
 * @param username
 */
bool usernameExists(string username);
};

#endif //_AUTHMANAGER_H