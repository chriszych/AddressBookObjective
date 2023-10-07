#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {

    char menuSelection;

    AddressBook addressBook("Users.txt", "Persons.txt");

    while (true)
    {
        if (!addressBook.isUserLoggedIn())
        {
            menuSelection = AuxiliaryMethods::selectMainMenuOption();

            switch (menuSelection)
            {
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
        }
        else
        {

           // if (adresaci.empty() == true)

            //    idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

            menuSelection = AuxiliaryMethods::selectUserMenuOption();

            switch (menuSelection)
            {
            case '1':
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                addressBook.addPerson();
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                cout << "Position No 2. Find Person by FirstName - TBD" << endl;
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                cout << "Position No 3. Find Person by SureName - TBD" << endl;
                break;
            case '4':
                addressBook.showAllPersons();
                break;
            case '5':
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                cout << "Position No 5. Delete Person - TBD" << endl;
                break;
            case '6':
                //edytujAdresata(adresaci);
                cout << "Position No 6. Edit Person - TBD" << endl;
                break;
            case '7':
                addressBook.changeLoggedUserPassword();
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                addressBook.logoutCurrentUser();
                //idZalogowanegoUzytkownika = 0;
                //adresaci.clear();
                break;
            }
        }
    }

//    addressBook.showAllUsers();
//    addressBook.registerUser();
//    addressBook.showAllUsers();
//    addressBook.loginUser();
//    addressBook.changeLoggedUserPassword();
//
//    addressBook.showAllPersons();
//    addressBook.addPerson();
//    addressBook.showAllPersons();
//
//    addressBook.logoutCurrentUser();
//    addressBook.showAllPersons();
//    addressBook.loginUser();
//    addressBook.showAllPersons();

    return 0;
}

#include "PersonManager.h"

int Testy01_main(){

    PersonManager personManager("Persons.txt", 2);
    personManager.showAllPersons();
    personManager.addPerson();
    personManager.showAllPersons();

    return 0;
}

#include "Person.h"
#include "PersonsFile.h"

int Testy02_main(){
    PersonsFile personsFile("Persons_test.txt");
    Person person(2, 1, "Jan", "Twarog", "39899032", "orzel@o3.pl", "ul Kwiatkowa 34");
    //Person person;
    personsFile.addPersonToFile(person);
    cout << personsFile.getIdLastPerson();
    return 0;
}
