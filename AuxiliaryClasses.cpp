#include "AuxiliaryClasses.h"

string AuxiliaryClasses::convertIntToString (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


