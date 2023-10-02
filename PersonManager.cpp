#include "PersonManager.h"

int PersonManager::addPerson() {
    Person person;

    system("cls");
    cout << " >>> ADDING NEW PERSON <<<" << endl << endl;
    person = enterNewPersonData();

    persons.push_back(person);
    personsFile.addPersonToFile(person);

    return idLastPerson;
}

Person PersonManager::enterNewPersonData() {
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

string PersonManager::changeFirstLetterToUpperAndRestLettersToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

void PersonManager::showAllPersons() {

    system("cls");
    if (!persons.empty()) {
        cout << "             >>> PERSONS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Person> :: iterator itr = persons.begin(); itr != persons.end(); itr++) {
            showPersonData(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Your AddressBook is empty." << endl << endl;
    }
    system("pause");
}

void PersonManager::showPersonData(Person person) {

    cout << endl << "Id:       " << person.getId() << endl;
    cout << "First Name:       " << person.getFirstName() << endl;
    cout << "Last Name:        " << person.getLastName() << endl;
    cout << "Phone number:     " << person.getPhoneNumber() << endl;
    cout << "Email:            " << person.getEmail() << endl;
    cout << "Address:          " << person.getAddress() << endl;
}


void PersonManager::clearAllPersons() {
    persons.clear();
}

void PersonManager::getAllPersonsForLoggedUserFromFile(int newIdLoggedUser) {
    idLoggedUser = newIdLoggedUser;
    idLastPerson = personsFile.getAllPersonsForLoggedUserFromFile(persons, newIdLoggedUser);
}

void PersonManager::setIdLoggedUser(int newIdLoggedUser) {
    idLoggedUser = newIdLoggedUser;
}

void PersonManager::setIdLastPerson(int newIdLastPerson) {
    idLastPerson = newIdLastPerson;
}

int PersonManager::getIdLoggedUser() {
    return idLoggedUser;
}

int PersonManager::getIdLastPerson() {
    return idLastPerson;
}
