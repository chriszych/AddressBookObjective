#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {

    int id;
    string login;
    string password;

public:

    int getId();
    string getLogin();
    string getPassword();

    void setId(int newId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
};
#endif
