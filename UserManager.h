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
        users = usersFile.readUsersFromFile();
    };

    int getIdLoggedUser();
    void setIdLoggedUser(int newIdLoggedUser);

    void registerUser();
    void showAllUsers();
    int loginUser();

    void changeLoggedUserPassword();
    void logoutCurrentUser();
    bool isUserLoggedIn();
};
#endif
