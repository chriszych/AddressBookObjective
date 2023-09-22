#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
    string userDataLine = "";
    textFile.open(usersFile.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDataLine = convertUserDataToLineSeparatedWithVerticalLines (user);

        if (isFileEmpty() == true)
        {
            textFile << userDataLine;
        }
        else
        {
            textFile << endl << userDataLine ;
        }
    }
    else
        cout << "Opening file " << usersFile << " not succeed, no data write to it." << endl;
    textFile.close();
}

bool UsersFile::isFileEmpty()
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string UsersFile::convertUserDataToLineSeparatedWithVerticalLines (User user)
{
    string userDataLine = "";

    userDataLine += AuxiliaryClasses::convertIntToString (user.getId ()) + '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}

vector <User> UsersFile::readUsersFromFile()
{
    vector <User> users;
    User user;
    string singleUserDataSeparatedWithVerticalLines = "";

    textFile.open(usersFile.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleUserDataSeparatedWithVerticalLines))
        {
            user = getUserData(singleUserDataSeparatedWithVerticalLines);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User UsersFile::getUserData(string singleUserDataSeparatedWithVerticalLines)
{
    User user;
    string singleUserData = "";
    int singleUserDataNumber = 1;

    for (size_t charPostion = 0; charPostion < singleUserDataSeparatedWithVerticalLines.length(); ++charPostion)
    {
        if (singleUserDataSeparatedWithVerticalLines[charPostion] != '|')
        {
            singleUserData += singleUserDataSeparatedWithVerticalLines[charPostion];
        }
        else
        {
            switch(singleUserDataNumber)
            {
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
