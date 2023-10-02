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

    int idLoggedUser;
    int idLastPerson;
    vector <Person> persons;
    PersonsFile personsFile;

    Person enterNewPersonData();
    string changeFirstLetterToUpperAndRestLettersToLower(string text);
    void showPersonData(Person person);


public:
    PersonManager(string fileName) : personsFile(fileName) {
        idLoggedUser = 0;
        idLastPerson = 0;
    };
    int addPerson();
    void showAllPersons();
    void getAllPersonsForLoggedUserFromFile(int idLoggedUser);
    void clearAllPersons();

    void setIdLoggedUser(int newIdLoggedUser);
    void setIdLastPerson(int newIdLastPerson);
    int getIdLoggedUser();
    int getIdLastPerson();

};

#endif
