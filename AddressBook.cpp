#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

    personManager.getAllPersonsForLoggedUserFromFile(userManager.loginUser());
}

void AddressBook::changeLoggedUserPassword() {

    userManager.changeLoggedUserPassword();
}

void AddressBook::logoutCurrentUser() {

    userManager.logoutCurrentUser();
    personManager.setIdLoggedUser(0);
    personManager.clearAllPersons();
}


void AddressBook::addPerson() {

    personManager.setIdLastPerson(personManager.addPerson());
}

void AddressBook::showAllPersons() {

    personManager.showAllPersons();
}



