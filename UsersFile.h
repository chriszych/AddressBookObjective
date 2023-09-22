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

    string usersFile;
    fstream textFile;

    bool isFileEmpty();
    string convertUserDataToLineSeparatedWithVerticalLines (User user);
    User getUserData (string singleUserDataSeparatedWithVerticalLines);

public:
    UsersFile();
    void addUserToFile(User user);
    vector <User> readUsersFromFile();

};

#endif
