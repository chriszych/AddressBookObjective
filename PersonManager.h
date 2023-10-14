#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Person.h"
#include "PersonsFile.h"

using namespace std;

class PersonManager {

    PersonsFile personsFile;
    const int ID_LOGGED_USER;
    vector <Person> persons;
    int idPersonToDelete;

    Person enterNewPersonData();
    void showPersonData(Person person);
    void displayPersonData(Person person);
    void displaySearchPersonNumber(int personsNumber);
    //int getLastPersonIdAfterDeletedSelectedPerson(int deletedPersonId, int lastPersonId);
    int enterIdOfSelectedPerson();



public:

    PersonManager(string fileName, int idLoggedUser)
        : personsFile(fileName), ID_LOGGED_USER(idLoggedUser) {
        personsFile.getAllPersonsForLoggedUserFromFile(persons, ID_LOGGED_USER);
    };

    void addPerson();
    void showAllPersons();
    void searchPersonByFirstName();
    void searchPersonByLastName();
    void deletePerson();
    void getLastPersonIdAfterDeletedSelectedPerson();

    int getIdPersonToDelete();
    void setIdPersonToDelete(int idPersonToDelete);


};

#endif
