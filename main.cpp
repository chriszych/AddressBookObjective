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
            case '1':
                addressBook.registerUser();
                break;
            case '2':
                addressBook.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            menuSelection = addressBook.selectUserMenuOption();

            switch (menuSelection) {
            case '1':
                addressBook.addPerson();
                break;
            case '2':
                cout << "Position No 2. Find Person by FirstName - TBD" << endl;
                system("pause");
                break;
            case '3':
                cout << "Position No 3. Find Person by SureName - TBD" << endl;
                system("pause");
                break;
            case '4':
                addressBook.showAllPersons();
                break;
            case '5':
                cout << "Position No 5. Delete Person - TBD" << endl;
                system("pause");
                break;
            case '6':
                cout << "Position No 6. Edit Person - TBD" << endl;
                system("pause");
                break;
            case '7':
                addressBook.changeLoggedUserPassword();
                break;
            case '8':
                addressBook.logoutCurrentUser();
                break;
            }
        }
    }

    return 0;
}
