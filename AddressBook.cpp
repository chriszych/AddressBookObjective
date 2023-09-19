#include "AddressBook.h"

AddressBook::AddressBook(){

    usersFile = "Users.txt";

}

void AddressBook::registerUser(){

    User user = enterNewUserData();

    Users.push_back(user);
    addUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");

}

User AddressBook::enterNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login, password;
    do
    {
        cout << "Enter login: ";
        //user.login = wczytajLinie();
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExist(user.getLogin()) == true);

    cout << "Enter password: ";
    //user.password = wczytajLinie();
    //cin >> user.password;
    cin >> password;
    user.setPassword(password);

    return user;
}

int AddressBook::getNewUserId()
{
    if (Users.empty() == true)
        return 1;
    else
        return Users.back().getId() + 1;
}

bool AddressBook::checkIfLoginExist(string login)
{
    for (size_t i=0; i < Users.size(); i++){
        if (Users[i].getLogin() == login){
            cout << endl << "User with entered login already exist." << endl;
            return true;
        }
    }
    return false;
}

void AddressBook::showAllUsers(){

    for (size_t i=0; i < Users.size(); i++){

            cout << Users[i].getId() << endl;
            cout << Users[i].getLogin() << endl;
            cout << Users[i].getPassword() << endl;
        }
}

void AddressBook::addUserToFile(User user)
{
    fstream textFile;
    string userDataLine = "";
    textFile.open(usersFile.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDataLine = convertUserDataToLineSeparatedWithVerticalLines (user);

        if (isFileEmpty(textFile) == true)
        {
            textFile << userDataLine;
        }
        else
        {
            textFile << endl << userDataLine ;
        }
    }
    else
        cout << "Opening file " << usersFile << " not succeed, no data write to it." << endl;
    textFile.close();
}

string AddressBook::convertUserDataToLineSeparatedWithVerticalLines (User user)
{
    string userDataLine = "";

    userDataLine += convertIntToString (user.getId ()) + '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}

string AddressBook::convertIntToString (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool AddressBook::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
