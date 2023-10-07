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

    const int ID_LOGGED_USER;
    vector <Person> persons;
    PersonsFile personsFile;

    Person enterNewPersonData();
    //string changeFirstLetterToUpperAndRestLettersToLower(string text);
    void showPersonData(Person person);


public:
    PersonManager(string fileName, int idLoggedUser)
        : personsFile(fileName), ID_LOGGED_USER(idLoggedUser)
    {
        //persons = personsFile.getAllPersonsForLoggedUserFromFile(persons, ID_LOGGED_USER);
        personsFile.getAllPersonsForLoggedUserFromFile(persons, ID_LOGGED_USER);
    };
    void addPerson();
    void showAllPersons();
    //void getAllPersonsForLoggedUserFromFile(int ID_LOGGED_USER);
    //void clearAllPersons();

    //void setIdLoggedUser(int newIdLoggedUser);
    //int getIdLoggedUser();

};

#endif
