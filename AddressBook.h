#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "PersonManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    PersonManager *personManager;
    const string PERSONS_FILE;

public:

    AddressBook(string userFileName, string personFileName)
        : userManager(userFileName), PERSONS_FILE(personFileName) {
        personManager = NULL;
    };
    ~AddressBook() {
        delete personManager;
        personManager = NULL;
    };

    void registerUser();
    void showAllUsers();
    void loginUser();
    void changeLoggedUserPassword();
    void logoutCurrentUser();
    bool isUserLoggedIn();

    char selectMainMenuOption();
    char selectUserMenuOption();

    void addPerson();
    void searchPersonByFirstName();
    void showAllPersons();

};

#endif
