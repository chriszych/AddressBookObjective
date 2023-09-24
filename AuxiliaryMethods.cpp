#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::readLine()
{
    string lineInput = "";
    getline(cin, lineInput);
    return lineInput;
}

bool AuxiliaryMethods::isFileEmpty(fstream &textFile)
{

    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
