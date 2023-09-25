#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString (int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::readLine() {
    string lineInput = "";
    getline(cin, lineInput);
    return lineInput;
}

bool AuxiliaryMethods::isFileEmpty(fstream &textFile) {

    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::getNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {
        number += text[charPosition];
        ++charPosition;
    }
    return number;
}
