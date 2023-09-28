#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

    userManager.loginUser();
}

void AddressBook::addPerson() {

    personManager.setIdLastPerson(personManager.addPerson());
}

void AddressBook::showAllPersons() {

    personManager.showAllPersons();
}

