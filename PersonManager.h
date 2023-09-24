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
    vector <Person> Persons;
    PersonsFile personsFile;

    Person enterNewPersonData();
    string changeFirstLetterToUpperAndRestLettersToLower(string text);
    void showPersonData(Person person);


public:
    PersonManager(string fileName) : personsFile(fileName) {};
    int addPerson();
    void showAllPersons();
    void setIdLoggedUser(int newIdLoggedUser);
    void getAllPersonsForLoggedUserFromFile();

};

#endif
