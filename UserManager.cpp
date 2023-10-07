#include "UserManager.h"

void UserManager::registerUser() {

    cout << "Registering new user: " << endl;
    User user = enterNewUserData();

    users.push_back(user);

    usersFile.addUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");

}

User UserManager::enterNewUserData() {
    User user;

    user.setId(getNewUserId());

    string login, password;
    do {
        cout << "Enter login: ";
         login = AuxiliaryMethods::readLine();
        user.setLogin(login);
    } while (checkIfLoginExist(user.getLogin()) == true);

    cout << "Enter password: ";
     password = AuxiliaryMethods::readLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkIfLoginExist(string login) {

    for (size_t i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "User with entered login already exist." << endl;
            return true;
        }
    }
    return false;
}


void UserManager::showAllUsers() {

    cout << "List of registered users: " << endl;
    for (size_t i=0; i < users.size(); i++) {

        cout << "(" << users[i].getId() << "). " << users[i].getLogin() << " : " << users[i].getPassword() << endl;
    }
}

int UserManager::getIdLoggedUser() {
    return idLoggedUser;
}

void UserManager::setIdLoggedUser(int newIdLoggedUser) {
    idLoggedUser = newIdLoggedUser;
}

int UserManager::loginUser() {
    string login = "", password = "";

    cout << "Logging user: " << endl;
    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attemptNumber = 3; attemptNumber > 0; attemptNumber--) {
                cout << "Enter password. Attempts remain: " << attemptNumber << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Login successfully." << endl << endl;
                    cout << endl << "user ID: " << itr -> getId() << endl << endl; //test
                    setIdLoggedUser(itr -> getId());
                    system("pause");
                    idLoggedUser = itr -> getId();
                    return idLoggedUser;
                }
            }
            cout << "You have entered 3 times wrong password." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "No user with such login." << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changeLoggedUserPassword() {

    string newPassword = "";

    cout << "Changing user password: " << endl;
    cout << "Enter new Password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == getIdLoggedUser()) {
            itr -> setPassword(newPassword);
            cout << "Password changed successfully." << endl << endl;
            system("pause");
        }
    }

    usersFile.saveAllUsersToFile(users);
}

void UserManager::logoutCurrentUser() {

    idLoggedUser = 0;
}

bool UserManager::isUserLoggedIn() {

        if(idLoggedUser > 0)
            return true;
        else
            return false;
}
