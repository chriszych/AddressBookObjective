#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook("Users.txt", "Persons.txt");

    //addressBook.showAllPersons();
    //addressBook.addPerson();
    //addressBook.addPerson();
    //addressBook.showAllPersons();
    //addressBook.addPerson();
    //addressBook.addPerson();
    //addressBook.addPerson();
    //addressBook.addPerson();
    //addressBook.showAllPersons();
    //addressBook.addPerson();
    //addressBook.showAllPersons();
    //addressBook.addPerson();
    //addressBook.showAllPersons();
    //addressBook.showAllUsers();
    //addressBook.registerUser();
    addressBook.loginUser();
    //addressBook.registerUser();
    //AddressBook addressBook2("Users2.txt");
    //addressBook2.showAllUsers();

    return 0;
}
