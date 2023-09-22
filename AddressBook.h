#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;

public:

    AddressBook(string fileName) : userManager(fileName) {
        userManager.readUsersFromFile();
    };
    void registerUser();
    void showAllUsers();

};

#endif
