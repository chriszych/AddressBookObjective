#include "PersonManager.h"

int PersonManager::addPerson()
{
    Person person;

    system("cls");
    cout << " >>> ADDING NEW PERSON <<<" << endl << endl;
    person = enterNewPersonData();

    Persons.push_back(person);
    personsFile.addPersonToFile(person);

    return ++idLastPerson;
}

Person PersonManager::enterNewPersonData()
{
    Person person;

    person.setId(++idLastPerson);
    person.setUserId(idLoggedUser);

    cout << "Enter FirstName: ";
    person.setFirstName(AuxiliaryMethods::readLine());
    person.setFirstName(changeFirstLetterToUpperAndRestLettersToLower(person.getFirstName()));

    cout << "Enter LastName: ";
    person.setLastName(AuxiliaryMethods::readLine());
    person.setLastName(changeFirstLetterToUpperAndRestLettersToLower(person.getLastName()));

    cout << "Enter Phone Number: ";
    person.setPhoneNumber(AuxiliaryMethods::readLine());

    cout << "Enter email: ";
    person.setEmail(AuxiliaryMethods::readLine());

    cout << "Enter address: ";
    person.setAddress(AuxiliaryMethods::readLine());

    return person;
}

string PersonManager::changeFirstLetterToUpperAndRestLettersToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
