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

    const string personsFile;

    string convertPersonDataToLineSeparatedWithVerticalLines(Person person);
    int getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    Person getPersonData(string singlePersonDataSeparatedWithVerticalLines);

public:

    PersonsFile(string fileName) : personsFile(fileName) {};
    void addPersonToFile(Person person);
    int getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser);

};
#endif
