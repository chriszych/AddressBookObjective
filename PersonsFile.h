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
    const string TEMP_PERSONS_FILE = "tmpPersons.txt";
    int idLastPerson;

    string convertPersonDataToLineSeparatedWithVerticalLines(Person person);
    int getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    int getUserIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines);
    Person getPersonData(string singlePersonDataSeparatedWithVerticalLines);
    void deleteFile(string fileName);
    void changeFileName(string oldFileName, string newFileName);
    int getLastPersonIdFromFile();


public:

    PersonsFile(string fileName) : PERSONS_FILE(fileName) {
        idLastPerson = 0;
    };

    bool addPersonToFile(Person person);
    void getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser);
    int returnSelectedPersonLineNumber(int personId);
    void deleteSelectedLineInFile(int deletedLineNumber);
    void getLastPersonIdAfterDeletedSelectedPerson(int deletedPersonId);

    void setIdLastPerson(int newIdLastPerson);
    int getIdLastPerson();

};
#endif
