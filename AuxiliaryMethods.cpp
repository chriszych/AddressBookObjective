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

string AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::readChar() {
    string lineInput = "";
    char lineChar  = {0};

    while (true) {
        getline(cin, lineInput);

        if (lineInput.length() == 1) {
            lineChar = lineInput[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return lineChar;
}

int AuxiliaryMethods::readInteger()
{
    string inputLine = "";
    int inputNumber = 0;

    while (true)
    {
        getline(cin, inputLine);

        stringstream myStream(inputLine);
        if (myStream >> inputNumber)
            break;
        cout << "This is not an integer number. Enter again. " << endl;
    }
    return inputNumber;
}
