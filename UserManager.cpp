#include "UserManager.h"

void UserManager::registerUser(){

    User user = enterNewUserData();

    Users.push_back(user);

    usersFile.addUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");

}

User UserManager::enterNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login, password;
    do
    {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExist(user.getLogin()) == true);

    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (Users.empty() == true)
        return 1;
    else
        return Users.back().getId() + 1;
}

bool UserManager::checkIfLoginExist(string login)
{
    for (size_t i=0; i < Users.size(); i++){
        if (Users[i].getLogin() == login){
            cout << endl << "User with entered login already exist." << endl;
            return true;
        }
    }
    return false;
}



void UserManager::showAllUsers(){

    for (size_t i=0; i < Users.size(); i++){

            cout << Users[i].getId() << endl;
            cout << Users[i].getLogin() << endl;
            cout << Users[i].getPassword() << endl;
        }
}

void UserManager::readUsersFromFile()
{
    Users = usersFile.readUsersFromFile();
}

int UserManager::getIdLoggedUser(){
    return idLoggedUser;
}
