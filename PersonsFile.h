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

public:

    PersonsFile(string fileName) : personsFile(fileName) {};
    void addPersonToFile(Person person);

};
#endif
