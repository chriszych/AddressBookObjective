#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class AddressBook {

    int idLoggedUser;
    int idDeletedUser;
    int idLastUser;

    vector <User> Users;

public:
    void registerUser();
    //int loginUser();

};
