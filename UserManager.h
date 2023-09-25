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
    vector <User> Users;
    UsersFile usersFile;

    User enterNewUserData();
    int getNewUserId();
    bool checkIfLoginExist(string login);

public:
    UserManager(string fileName) : usersFile(fileName) {};
    void registerUser();
    void showAllUsers();
    void readUsersFromFile();
    int getIdLoggedUser();
    //int loginUser();
    //void changeLoggedUserPassword();
    //void logoutCurrentUser();
    //string getUserData(string);
};

#endif
