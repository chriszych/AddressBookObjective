#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

    idLoggedUser = userManager.loginUser();
}

void AddressBook::changeLoggedUserPassword() {

    userManager.changeLoggedUserPassword(idLoggedUser);
}


void AddressBook::addPerson() {

    personManager.setIdLastPerson(personManager.addPerson());
}

void AddressBook::showAllPersons() {

    personManager.showAllPersons();
}

void AddressBook::getAllPersonsForLoggedUserFromFile(){

    personManager.getAllPersonsForLoggedUserFromFile(idLoggedUser);
}

void AddressBook::setIdLoggedUser(int newIdLoggedUser){
    idLoggedUser = newIdLoggedUser;
}

int AddressBook::getIdLogedUser(){
    return idLoggedUser;
}


