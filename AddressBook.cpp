#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

    userManager.loginUser();
    if(userManager.isUserLoggedIn())
    {
        personManager = new PersonManager(PERSONS_FILE, userManager.getIdLoggedUser());
    }
}

void AddressBook::changeLoggedUserPassword() {

    userManager.changeLoggedUserPassword();
}

void AddressBook::logoutCurrentUser() {

    userManager.logoutCurrentUser();
    delete personManager;
    personManager = NULL;
    //personManager.setIdLoggedUser(0);
    //personManager.clearAllPersons();
}


void AddressBook::addPerson() {

    if(userManager.isUserLoggedIn()){
        personManager -> addPerson();
    } else {
        cout << "To add person you have to be logged first." << endl;
        system("pause");
    }
}

void AddressBook::showAllPersons() {

    if(userManager.isUserLoggedIn()){
        personManager -> showAllPersons();
    } else {
        cout << "To show persons you have to be logged first." << endl;
        system("pause");
    }
}

bool AddressBook::isUserLoggedIn() {

    if(userManager.isUserLoggedIn()){
        return true;
    } else {
        return false;
    }
}


