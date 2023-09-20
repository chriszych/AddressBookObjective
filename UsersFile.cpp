#include "UsersFile.h"

UsersFile::UsersFile(){
    usersFile = "Users.txt";
}

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
