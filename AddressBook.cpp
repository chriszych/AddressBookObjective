#include "AddressBook.h"


void AddressBook::registerUser() {

    userManager.registerUser();
}

void AddressBook::showAllUsers() {

    userManager.showAllUsers();
}

void AddressBook::loginUser() {

    userManager.loginUser();
    if(userManager.isUserLoggedIn()) {
        personManager = new PersonManager(PERSONS_FILE, userManager.getIdLoggedUser());
    }
}

void AddressBook::changeLoggedUserPassword() {

    userManager.changeLoggedUserPassword();
}

void AddressBook::logoutCurrentUser() {

    userManager.logoutCurrentUser();
    delete personManager;
    personManager = NULL;
}

void AddressBook::addPerson() {

    if(userManager.isUserLoggedIn()) {
        personManager -> addPerson();
    } else {
        cout << "To add person you have to be logged first." << endl;
        system("pause");
    }
}

void AddressBook::showAllPersons() {

    if(userManager.isUserLoggedIn()) {
        personManager -> showAllPersons();
    } else {
        cout << "To show persons you have to be logged first." << endl;
        system("pause");
    }
}

bool AddressBook::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

char AddressBook::selectMainMenuOption() {

    char menuSelection;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Login user" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    menuSelection = AuxiliaryMethods::readChar();

    return menuSelection;
}

char AddressBook::selectUserMenuOption() {

    char menuSelection;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Person" << endl;
    cout << "2. Search by First Name" << endl;
    cout << "3. Search by Last Name" << endl;
    cout << "4. Show All Persons" << endl;
    cout << "5. Delete Person" << endl;
    cout << "6. Modify Person" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    menuSelection = AuxiliaryMethods::readChar();

    return menuSelection;
}

void AddressBook::searchPersonByFirstName() {

    personManager -> searchPersonByFirstName();
}

void AddressBook::searchPersonByLastName() {

    personManager -> searchPersonByLastName();
}

void AddressBook::deletePerson() {

    personManager -> deletePerson();
    personManager -> getLastPersonIdAfterDeletedSelectedPerson();
    //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
}
