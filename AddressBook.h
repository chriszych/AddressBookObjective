#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "PersonManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    PersonManager personManager;

public:

    AddressBook(string userFileName, string personFileName) : userManager(userFileName), personManager(personFileName) {
        userManager.readUsersFromFile();
    };
    void registerUser();
    void showAllUsers();
    void loginUser();

    void addPerson();
    void showAllPersons();
};

#endif
