#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <sstream>
#include <iostream>


#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {

public:

    static string convertIntToString (int number);
    static int convertStringToInt(string number);
    static string readLine();
    static bool isFileEmpty(fstream &textFile);
    static string getNumber(string text, int charPosition);
    static string changeFirstLetterToUpperAndRestLettersToLower(string text);
    static char readChar();

};

#endif
