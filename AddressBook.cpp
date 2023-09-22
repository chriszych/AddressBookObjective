#include "AddressBook.h"


AddressBook::AddressBook(){
    userManager.readUsersFromFile();
}


  void AddressBook::registerUser(){

  userManager.registerUser();
  }

  void AddressBook::showAllUsers(){

  userManager.showAllUsers();
  }




