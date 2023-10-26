#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {

    char menuSelection;

    AddressBook addressBook("Users.txt", "Persons.txt");

    while (true) {
        if (!addressBook.isUserLoggedIn()) {
            menuSelection = addressBook.selectMainMenuOption();

            switch (menuSelection) {
            case '1': addressBook.registerUser(); break;
            case '2': addressBook.loginUser(); break;
            case '9': exit(0); break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            menuSelection = addressBook.selectUserMenuOption();

            switch (menuSelection) {
            case '1': addressBook.addPerson(); break;
            case '2': addressBook.searchPersonByFirstName(); break;
            case '3': addressBook.searchPersonByLastName(); break;
            case '4': addressBook.showAllPersons(); break;
            case '5': addressBook.deletePerson(); break;
            case '6': addressBook.modifyPerson(); break;
            case '7': addressBook.changeLoggedUserPassword(); break;
            case '8': addressBook.logoutCurrentUser(); break;

            }
        }
    }

    return 0;
}
