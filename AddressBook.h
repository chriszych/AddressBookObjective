#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"

using namespace std;

class AddressBook {

    int idLoggedUser;
    int idDeletedUser;
    int idLastUser;

    vector <User> Users;

    User enterNewUserData();
    int getNewUserId();
    bool checkIfLoginExist(string login);

public:
    void registerUser();
    void showAllUsers();

};
