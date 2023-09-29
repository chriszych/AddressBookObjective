#include "PersonsFile.h"

string PersonsFile::convertPersonDataToLineSeparatedWithVerticalLines(Person person) {
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

void PersonsFile::addPersonToFile(Person person) {
    string personDataLine = "";
    fstream textFile;
    textFile.open(personsFile.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        personDataLine = convertPersonDataToLineSeparatedWithVerticalLines(person);

        if (AuxiliaryMethods::isFileEmpty(textFile) == true) {
            textFile << personDataLine;
        } else {
            textFile << endl << personDataLine ;
        }
    } else {
        cout << "Failed to open " << personsFile << " and save data to it." << endl;
    }
    textFile.close();
    system("pause");
}

int PersonsFile::getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser)
//int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    Person person;
    int idLastPerson = 0;
    string singlePersonDataSeparatedWithVerticalLines = "";
    string lastPersonInFileData = "";
    fstream textFile;
    textFile.open(personsFile.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singlePersonDataSeparatedWithVerticalLines)) {
            if(idLoggedUser == getUserIdFromDataSeparatedWithVerticalLines(singlePersonDataSeparatedWithVerticalLines)) {
                person = getPersonData(singlePersonDataSeparatedWithVerticalLines);
                persons.push_back(person);
            }
        }
        lastPersonInFileData = singlePersonDataSeparatedWithVerticalLines;
    } else
        cout << "Failed to open " << personsFile << " file and read data from it." << endl;

    textFile.close();

    if (lastPersonInFileData != "") {
        idLastPerson = getPersonIdFromDataSeparatedWithVerticalLines(lastPersonInFileData);
        return idLastPerson;
    } else
        return 0;
}

int PersonsFile::getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines) {
    int personIdStartPosition = 0;
    int personId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getNumber(singlePersonDataSeparatedWithVerticalLines, personIdStartPosition));
    return personId;
}

int PersonsFile::getUserIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines)
{
    int userIdStartPosition = singlePersonDataSeparatedWithVerticalLines.find_first_of('|') + 1;
    int userId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getNumber(singlePersonDataSeparatedWithVerticalLines, userIdStartPosition));

    return userId;
}

Person PersonsFile::getPersonData(string singlePersonDataSeparatedWithVerticalLines) {
    Person person;
    string singlePersonData = "";
    int singlePersonDataNumber = 1;

    for (size_t charPosition = 0; charPosition < singlePersonDataSeparatedWithVerticalLines.length(); ++charPosition) {
        if (singlePersonDataSeparatedWithVerticalLines[charPosition] != '|') {
            singlePersonData += singlePersonDataSeparatedWithVerticalLines[charPosition];
        } else {
            switch(singlePersonDataNumber) {
            case 1:
                person.setId(atoi(singlePersonData.c_str()));
                break;
            case 2:
                person.setUserId(atoi(singlePersonData.c_str()));
                break;
            case 3:
                person.setFirstName(singlePersonData);
                break;
            case 4:
                person.setLastName(singlePersonData);
                break;
            case 5:
                person.setPhoneNumber(singlePersonData);
                break;
            case 6:
                person.setEmail(singlePersonData);
                break;
            case 7:
                person.setAddress(singlePersonData);
                break;
            }
            singlePersonData = "";
            singlePersonDataNumber++;
        }
    }
    return person;
}
