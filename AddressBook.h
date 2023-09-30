#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "PersonManager.h"

using namespace std;

class AddressBook {

   // int idLoggedUser;
    UserManager userManager;
    PersonManager personManager;

public:

    AddressBook(string userFileName, string personFileName) : userManager(userFileName), personManager(personFileName) {
        userManager.readUsersFromFile();
    };
    void registerUser();
    void showAllUsers();
    void loginUser();
    void changeLoggedUserPassword();
    void logoutCurrentUser();

    void addPerson();
    void showAllPersons();
//    void getAllPersonsForLoggedUserFromFile();

//    void setIdLoggedUser(int newIdLoggedUser);
//    int getIdLogedUser();
};

#endif
