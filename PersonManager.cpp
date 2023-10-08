#include "PersonManager.h"

void PersonManager::addPerson() {
    Person person;

    system("cls");
    cout << " >>> ADDING NEW PERSON <<<" << endl << endl;
    person = enterNewPersonData();

    persons.push_back(person);
    if(personsFile.addPersonToFile(person)) {
        cout << "New person added successfully." << endl;
    } else {
        cout << "Error. Failed to add new user to the file." << endl;
        system("pause");
    }
}

Person PersonManager::enterNewPersonData() {
    Person person;

    person.setId(personsFile.getIdLastPerson()+1);
    person.setUserId(ID_LOGGED_USER);

    cout << "Enter FirstName: ";
    person.setFirstName(AuxiliaryMethods::readLine());
    person.setFirstName(AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(person.getFirstName()));

    cout << "Enter LastName: ";
    person.setLastName(AuxiliaryMethods::readLine());
    person.setLastName(AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(person.getLastName()));

    cout << "Enter Phone Number: ";
    person.setPhoneNumber(AuxiliaryMethods::readLine());

    cout << "Enter email: ";
    person.setEmail(AuxiliaryMethods::readLine());

    cout << "Enter address: ";
    person.setAddress(AuxiliaryMethods::readLine());

    return person;
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

