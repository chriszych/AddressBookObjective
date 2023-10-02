#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {

    int idLoggedUser;
    vector <User> users;
    UsersFile usersFile;

    User enterNewUserData();
    int getNewUserId();
    bool checkIfLoginExist(string login);

public:
    UserManager(string fileName) : usersFile(fileName) {
        idLoggedUser = 0;
    };
    void registerUser();
    void showAllUsers();
    void readUsersFromFile();
    int loginUser();

    void changeLoggedUserPassword();
    void logoutCurrentUser();

    int getIdLoggedUser();
    void setIdLoggedUser(int newIdLoggedUser);
};

#endif
