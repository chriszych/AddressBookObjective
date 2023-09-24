#include "PersonsFile.h"

string PersonsFile::convertPersonDataToLineSeparatedWithVerticalLines(Person person){
    string personDataLine = "";

    personDataLine += AuxiliaryMethods::convertIntToString(person.getId()) + '|';
    personDataLine += AuxiliaryMethods::convertIntToString(person.getUserId()) + '|';
    personDataLine += person.getFirstName() + '|';
    personDataLine += person.getLastName() + '|';
    personDataLine += person.getPhoneNumber() + '|';
    personDataLine += person.getEmail() + '|';
    personDataLine += person.getAddress() + '|';

    return personDataLine;
}

void PersonsFile::addPersonToFile(Person person){
    string personDataLine = "";
    fstream textFile;
    textFile.open(personsFile.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        personDataLine = convertPersonDataToLineSeparatedWithVerticalLines(person);

        if (AuxiliaryMethods::isFileEmpty(textFile) == true)
        {
            textFile << personDataLine;
        }
        else
        {
            textFile << endl << personDataLine ;
        }
    }
    else
    {
        cout << "Failed to open " << personsFile << " and save data to it." << endl;
    }
    textFile.close();
    system("pause");
}


