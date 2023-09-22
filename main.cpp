#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt");

    addressBook.showAllUsers();
    //addressBook.registerUser();
    //addressBook.registerUser();
    AddressBook addressBook2("Users2.txt");
    addressBook2.showAllUsers();

    return 0;
}
