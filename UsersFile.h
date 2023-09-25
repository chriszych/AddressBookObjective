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

    const string usersFile;

    string convertUserDataToLineSeparatedWithVerticalLines (User user);
    User getUserData (string singleUserDataSeparatedWithVerticalLines);
    //void saveAllUsersToFile();

public:
    UsersFile(string fileName) : usersFile(fileName) {};
    void addUserToFile(User user);
    vector <User> readUsersFromFile();

};

#endif
