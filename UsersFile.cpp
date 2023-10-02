#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    string userDataLine = "";
    fstream textFile;

    textFile.open(usersFile.c_str(), ios::app);

    if (textFile.good() == true) {
        userDataLine = convertUserDataToLineSeparatedWithVerticalLines (user);

        if (AuxiliaryMethods::isFileEmpty(textFile) == true) {
            textFile << userDataLine;
        } else {
            textFile << endl << userDataLine ;
        }
    } else
        cout << "Opening file " << usersFile << " not succeed, no data write to it." << endl;
    textFile.close();
}


string UsersFile::convertUserDataToLineSeparatedWithVerticalLines (User user) {
    string userDataLine = "";

    userDataLine += AuxiliaryMethods::convertIntToString (user.getId ()) + '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}

vector <User> UsersFile::readUsersFromFile() {
    fstream textFile;
    vector <User> users;
    User user;
    string singleUserDataSeparatedWithVerticalLines = "";

    textFile.open(usersFile.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singleUserDataSeparatedWithVerticalLines)) {
            user = getUserData(singleUserDataSeparatedWithVerticalLines);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User UsersFile::getUserData(string singleUserDataSeparatedWithVerticalLines) {
    User user;
    string singleUserData = "";
    int singleUserDataNumber = 1;

    for (size_t charPostion = 0; charPostion < singleUserDataSeparatedWithVerticalLines.length(); ++charPostion) {
        if (singleUserDataSeparatedWithVerticalLines[charPostion] != '|') {
            singleUserData += singleUserDataSeparatedWithVerticalLines[charPostion];
        } else {
            switch(singleUserDataNumber) {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

void UsersFile::saveAllUsersToFile(vector <User> &users) {
    fstream textFile;
    string userDataLine = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(usersFile.c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            userDataLine = convertUserDataToLineSeparatedWithVerticalLines(*itr);

            if (itr == itrEnd) {
                textFile << userDataLine;
            } else {
                textFile << userDataLine << endl;
            }
            userDataLine = "";
        }
    } else {
        cout << "Failed to open " << usersFile << " file." << endl;
    }
    textFile.close();
}
