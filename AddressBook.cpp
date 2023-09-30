#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

//    idLoggedUser = userManager.loginUser();
//    personManager.getAllPersonsForLoggedUserFromFile(idLoggedUser);
    personManager.getAllPersonsForLoggedUserFromFile(userManager.loginUser());
}

void AddressBook::changeLoggedUserPassword() {

    //userManager.changeLoggedUserPassword(idLoggedUser);
    userManager.changeLoggedUserPassword();
}

void AddressBook::logoutCurrentUser() {

//    idLoggedUser = 0;
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

//void AddressBook::getAllPersonsForLoggedUserFromFile(){
//
//    personManager.getAllPersonsForLoggedUserFromFile(idLoggedUser);
//}

//void AddressBook::setIdLoggedUser(int newIdLoggedUser){
//    idLoggedUser = newIdLoggedUser;
//}
//
//int AddressBook::getIdLogedUser(){
//    return idLoggedUser;
//}


