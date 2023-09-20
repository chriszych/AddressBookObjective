#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AuxiliaryClasses.h"

using namespace std;

class UsersFile {

    string usersFile;
    fstream textFile;

    bool isFileEmpty();
    string convertUserDataToLineSeparatedWithVerticalLines (User user);

public:
    UsersFile();
    void addUserToFile(User user);

};

#endif
