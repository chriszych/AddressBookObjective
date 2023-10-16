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

bool PersonsFile::addPersonToFile(Person person) {
    string personDataLine = "";
    fstream textFile;
    textFile.open(TEXT_FILE.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        personDataLine = convertPersonDataToLineSeparatedWithVerticalLines(person);

        if (isFileEmpty(textFile) == true) {
            textFile << personDataLine;
        } else {
            textFile << endl << personDataLine ;
        }

        idLastPerson++;
        textFile.close();
        return true;
    }
    return false;
}

void PersonsFile::getAllPersonsForLoggedUserFromFile(vector <Person> &persons, int idLoggedUser) {
    Person person;
    string singlePersonDataSeparatedWithVerticalLines = "";
    string lastPersonInFileData = "";
    fstream textFile;

    textFile.open(TEXT_FILE.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singlePersonDataSeparatedWithVerticalLines)) {
            if(idLoggedUser == getUserIdFromDataSeparatedWithVerticalLines(singlePersonDataSeparatedWithVerticalLines)) {
                person = getPersonData(singlePersonDataSeparatedWithVerticalLines);
                persons.push_back(person);
            }
        }
        lastPersonInFileData = singlePersonDataSeparatedWithVerticalLines;
    } else
        cout << "Failed to open " << TEXT_FILE << " file and read data from it." << endl;

    textFile.close();

    if (lastPersonInFileData != "") {
        idLastPerson = getPersonIdFromDataSeparatedWithVerticalLines(lastPersonInFileData);
    }
}

int PersonsFile::getPersonIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines) {
    int personIdStartPosition = 0;
    int personId = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::getNumber(singlePersonDataSeparatedWithVerticalLines, personIdStartPosition));
    return personId;
}

int PersonsFile::getUserIdFromDataSeparatedWithVerticalLines(string singlePersonDataSeparatedWithVerticalLines) {
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

void PersonsFile::setIdLastPerson(int idLastPerson) {
    this -> idLastPerson = idLastPerson;
}

int PersonsFile::getIdLastPerson() {
    return idLastPerson;
}

void PersonsFile::deleteSelectedPersonInFile(int personId) {
    fstream readTextFile, tmpTextFile;
    string readLine = "";
    int linePersonId = 0;

    setIdLastPerson(getLastPersonIdFromFile());
    if (personId == getIdLastPerson()) {
        setIdLastPerson(getOneBeforeLastPersonIdFromFile());
    }

    readTextFile.open(TEXT_FILE.c_str(), ios::in);
    tmpTextFile.open(TEMP_PERSONS_FILE.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true && personId != 0) {
        while (getline(readTextFile, readLine)) {

            linePersonId = getPersonIdFromDataSeparatedWithVerticalLines(readLine);

            if(personId == linePersonId) {}
            else {
                if (linePersonId == getIdLastPerson()) {
                    tmpTextFile << readLine;
                } else {
                    tmpTextFile << readLine << endl;
                }
            }
        }
    }

    readTextFile.close();
    tmpTextFile.close();

    deleteFile(TEXT_FILE);
    changeFileName(TEMP_PERSONS_FILE, TEXT_FILE);
}


void PersonsFile::deleteFile(string fileName) {
    if (remove(fileName.c_str()) == 0) {}
    else
        cout << "Failed to delete the file " << fileName << endl;
}

void PersonsFile::changeFileName(string oldFileName, string newFileName) {
    if (rename(oldFileName.c_str(), newFileName.c_str()) == 0) {}
    else
        cout << "File name was not changed." << oldFileName << endl;
}

int PersonsFile::getLastPersonIdFromFile() {
    int lastPersonId = 0;
    string singlePersonDataSeparatedWithVerticalLines = "";
    string lastPersonInFileData = "";
    fstream textFile;

    textFile.open(TEXT_FILE.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singlePersonDataSeparatedWithVerticalLines)) {}
        lastPersonInFileData = singlePersonDataSeparatedWithVerticalLines;
        textFile.close();
    } else
        cout << "Failed to open the file and read the data." << endl;

    if (lastPersonInFileData != "") {
        lastPersonId = getPersonIdFromDataSeparatedWithVerticalLines(lastPersonInFileData);
    }
    return lastPersonId;
}

int PersonsFile::getOneBeforeLastPersonIdFromFile() {
    int oneBeforeLastPersonId = 0;
    string singlePersonDataSeparatedWithVerticalLines = "";
    string lastPersonInFileData = "";
    string oneBeforeLastPersonInFileData = "";
    fstream textFile;

    textFile.open(TEXT_FILE.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singlePersonDataSeparatedWithVerticalLines)) {
            oneBeforeLastPersonInFileData = lastPersonInFileData ;
            lastPersonInFileData = singlePersonDataSeparatedWithVerticalLines;
        }
        textFile.close();
    } else
        cout << "Failed to open the file and read the data." << endl;

    if (oneBeforeLastPersonInFileData != "") {
        oneBeforeLastPersonId = getPersonIdFromDataSeparatedWithVerticalLines(oneBeforeLastPersonInFileData);
    }
    return oneBeforeLastPersonId;
}

void PersonsFile::getLastPersonIdAfterDeletedSelectedPerson(int deletedPersonId) {
    if (deletedPersonId == idLastPerson)
        setIdLastPerson(getLastPersonIdFromFile());
}

void PersonsFile::modifySelectedPersonInFile(Person person) {

    fstream readTextFile, tmpTextFile;
    string readLine = "";
    string personDataLine = "";
    int linePersonId = 0;


    setIdLastPerson(getLastPersonIdFromFile());


    personDataLine = convertPersonDataToLineSeparatedWithVerticalLines(person);

    readTextFile.open(TEXT_FILE.c_str(), ios::in);
    tmpTextFile.open(TEMP_PERSONS_FILE.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true && person.getId() != 0) {
        while (getline(readTextFile, readLine)) {

            linePersonId = getPersonIdFromDataSeparatedWithVerticalLines(readLine);

            if(person.getId() == linePersonId) {

                if (linePersonId == getIdLastPerson()) {
                    tmpTextFile << personDataLine;
                } else {
                    tmpTextFile << personDataLine << endl;
                }
            } else {
                if (linePersonId == getIdLastPerson()) {
                    tmpTextFile << readLine;
                } else {
                    tmpTextFile << readLine << endl;
                }
            }
        }
    }

    readTextFile.close();
    tmpTextFile.close();

    deleteFile(TEXT_FILE);
    changeFileName(TEMP_PERSONS_FILE, TEXT_FILE);
}
