#ifndef PERSONSFILE_H
#define PERSONSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Person.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonsFile {

    const string PERSONS_FILE;
    int idLastPerson;

    string convertPersonDataToLineSeparatedWithVerticalLines(Person person);
    int getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    int getUserIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    Person getPersonData(string singlePersonDataSeparatedWithVerticalLines);

public:

    PersonsFile(string fileName) : PERSONS_FILE(fileName) {
        idLastPerson = 0;
    };

    bool addPersonToFile(Person person);
    void getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser);

    void setIdLastPerson(int newIdLastPerson);
    int getIdLastPerson();

};
#endif
