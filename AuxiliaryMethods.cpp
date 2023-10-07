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

char AuxiliaryMethods::readChar()
{
    string lineInput = "";
    char lineChar  = {0};

    while (true)
    {
        getline(cin, lineInput);

        if (lineInput.length() == 1)
        {
            lineChar = lineInput[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return lineChar;
}

char AuxiliaryMethods::selectMainMenuOption()
{
    char menuSelection;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Login user" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    menuSelection = readChar();

    return menuSelection;
}

char AuxiliaryMethods::selectUserMenuOption()
{
    char menuSelection;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Person" << endl;
    cout << "2. Search by First Name" << endl;
    cout << "3. Search by Last Name" << endl;
    cout << "4. Show All Persons" << endl;
    cout << "5. Delete Person" << endl;
    cout << "6. Modify Person" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    menuSelection = readChar();

    return menuSelection;
}
