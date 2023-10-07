#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile {

    const string USERS_FILE;

    string convertUserDataToLineSeparatedWithVerticalLines (User user);
    User getUserData (string singleUserDataSeparatedWithVerticalLines);


public:
    UsersFile(string fileName) : USERS_FILE(fileName) {};
    void addUserToFile(User user);
    vector <User> readUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);

};

#endif
