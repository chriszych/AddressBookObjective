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

public:

    int addPerson();

};

#endif
