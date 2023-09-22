#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryClasses.h"

using namespace std;

class UsersFile {

    const string usersFile;
    fstream textFile;

    bool isFileEmpty();
    string convertUserDataToLineSeparatedWithVerticalLines (User user);
    User getUserData (string singleUserDataSeparatedWithVerticalLines);

public:
    UsersFile(string fileName) : usersFile(fileName) {};
    void addUserToFile(User user);
    vector <User> readUsersFromFile();

};

#endif
