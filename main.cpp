#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook;

    addressBook.showAllUsers();
    addressBook.registerUser();
    addressBook.registerUser();
    addressBook.showAllUsers();

    return 0;
}
