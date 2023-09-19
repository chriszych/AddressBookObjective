#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"

using namespace std;

class AddressBook {

    int idLoggedUser;
    int idDeletedUser;
    int idLastUser;

    string usersFile;

    vector <User> Users;

    User enterNewUserData();
    int getNewUserId();
    bool checkIfLoginExist(string login);
    void addUserToFile(User user);
    string convertUserDataToLineSeparatedWithVerticalLines (User user);
    string convertIntToString (int number);
    bool isFileEmpty(fstream &textFile);

public:
    AddressBook();
    void registerUser();
    void showAllUsers();

};
