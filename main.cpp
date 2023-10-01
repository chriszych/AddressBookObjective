#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook("Users.txt", "Persons.txt");

    addressBook.showAllUsers();
    addressBook.registerUser();
    addressBook.showAllUsers();
    addressBook.loginUser();
    addressBook.changeLoggedUserPassword();

    addressBook.showAllPersons();
    addressBook.addPerson();
    addressBook.showAllPersons();

    addressBook.logoutCurrentUser();
    addressBook.showAllPersons();
    addressBook.loginUser();
    addressBook.showAllPersons();

    return 0;
}
