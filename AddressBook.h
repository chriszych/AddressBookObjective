#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;

public:

    void registerUser();
    void showAllUsers();

};

#endif
