#ifndef PERSONSFILE_H
#define PERSONSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "TextFile.h"
#include "Person.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonsFile : public TextFile {

    const string TEMP_PERSONS_FILE = "tmpPersons.txt";
    int idLastPerson;


    int getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    int getUserIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    Person getPersonData(string singlePersonDataSeparatedWithVerticalLines);
    void deleteFile(string fileName);
    void changeFileName(string oldFileName, string newFileName);
    string convertPersonDataToLineSeparatedWithVerticalLines(Person person);

public:

    PersonsFile(string fileName) : TextFile(fileName) {
        idLastPerson = 0;
    };

    int getIdLastPerson();
    void setIdLastPerson(int newIdLastPerson);

    bool addPersonToFile(Person person);
    void getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser);
    void deleteSelectedPersonInFile(int personId);
    void modifySelectedPersonInFile(Person person);

};
#endif
