#include "AddressBook.h"

void AddressBook::registerUser(){

    User user = enterNewUserData();

    Users.push_back(user);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");

}

User AddressBook::enterNewUserData()
{
    User user;

    //user.id = getNewUserId();
    user.setId(getNewUserId());

    string login, password;
    do
    {
        cout << endl << "Enter login: ";
        //user.login = wczytajLinie();
        //cin >> user.login;
        cin >> login;
        user.setLogin(login);
    //} while (checkIfLoginExist(user.login) == true);
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
    vector <User>::iterator itr = Users.begin();
    while (itr != Users.end())
    {
        if (itr -> getLogin() == login)
        {
            cout << endl << "User with entered login already exist." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}
