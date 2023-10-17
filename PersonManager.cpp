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

void PersonManager::searchPersonByFirstName() {

    string firstNameToSearch = "";
    int personsNumber = 0;

    system("cls");
    if (!persons.empty()) {
        cout << ">>> SEARCH PERSONS BY FIRSTNAME <<<" << endl << endl;

        cout << "Search person by first name: ";
        firstNameToSearch = AuxiliaryMethods::readLine();
        firstNameToSearch = AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(firstNameToSearch);

        for (vector <Person>::iterator  itr = persons.begin(); itr != persons.end(); itr++) {
            if (itr -> getFirstName() == firstNameToSearch) {
                displayPersonData(*itr);
                personsNumber++;
            }
        }
        displaySearchPersonNumber(personsNumber);
    } else {
        cout << endl << "Your AddressBook is empty!" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void PersonManager::searchPersonByLastName() {
    string lastNameToSearch = "";
    int personsNumber = 0;

    system("cls");
    if (!persons.empty()) {
        cout << ">>> SEARCH PERSONS BY LASTNAME <<<" << endl << endl;

        cout << "Search person by last name: ";
        lastNameToSearch = AuxiliaryMethods::readLine();
        lastNameToSearch = AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(lastNameToSearch);

        for (vector <Person>::iterator  itr = persons.begin(); itr != persons.end(); itr++) {
            if (itr -> getLastName() == lastNameToSearch) {
                displayPersonData(*itr);
                personsNumber++;
            }
        }
        displaySearchPersonNumber(personsNumber);
    } else {
        cout << endl << "Your AddressBook is empty!" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void PersonManager::displayPersonData(Person person) {
    cout << endl << "Id:         " << person.getId() << endl;
    cout << "Firstname:          " << person.getFirstName() << endl;
    cout << "Lastname:           " << person.getLastName() << endl;
    cout << "Phone :             " << person.getPhoneNumber() << endl;
    cout << "Email:              " << person.getEmail() << endl;
    cout << "Address:            " << person.getAddress() << endl;
}

void PersonManager::displaySearchPersonNumber(int personsNumber) {
    if (personsNumber == 0)
        cout << endl << "No such persons in your AddressBook." << endl;
    else
        cout << endl << "Number of persons in your AddressBook: " << personsNumber << endl << endl;
}

void PersonManager::deletePerson() {

    system("cls");
    cout << ">>> DELETE SELECTED PERSON <<<" << endl << endl;
    setIdPersonToDelete(enterIdOfSelectedPerson());

    char replyChar;
    bool ifPersonExist = false;

    for (vector <Person>::iterator itr = persons.begin(); itr != persons.end(); itr++) {
        if (itr -> getId() == getIdPersonToDelete()) {
            ifPersonExist = true;
            cout << endl << "Confirm by pressing the key 'y': ";
            replyChar = AuxiliaryMethods::readChar();
            if (replyChar == 'y') {
                personsFile.deleteSelectedPersonInFile(getIdPersonToDelete());

                persons.erase(itr);
                cout << endl << endl << "Selected person had been DELETED." << endl << endl;
                system("pause");
                break;
            } else {
                cout << endl << endl << "Selected person had NOT been deleted." << endl << endl;
                system("pause");
            }
        }
    }
    if (ifPersonExist == false) {
        cout << endl << "No such person in your AddressBook" << endl << endl;
        system("pause");
    }
}

int PersonManager::enterIdOfSelectedPerson() {
    int IdSelectedPerson = 0;
    cout << "Enter selected person ID: ";
    IdSelectedPerson = AuxiliaryMethods::readInteger();
    return IdSelectedPerson ;
}

int PersonManager::getIdPersonToDelete() {
    return idPersonToDelete;
}

void PersonManager::setIdPersonToDelete(int idPersonToDelete) {
    this -> idPersonToDelete = idPersonToDelete;
}

void PersonManager::modifyPerson() {

    system("cls");
    Person person;
    int idEditPerson = 0;
    string personDataLine = "";

    cout << ">>> MODIFY SELECTED PERSON <<<" << endl << endl;
    idEditPerson = enterIdOfSelectedPerson();

    char replyChar;
    bool ifPersonExist = false;

    for (size_t i = 0; i < persons.size(); i++) {
        if (persons[i].getId() == idEditPerson) {
            ifPersonExist = true;
            replyChar = selectMenuEditOption();

            switch (replyChar) {
            case '1':
                cout << "Enter new first name: ";
                persons[i].setFirstName(AuxiliaryMethods::readLine());
                persons[i].setFirstName(AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(persons[i].getFirstName()));
                modifySelectedPersonData(persons[i]);
                break;
            case '2':
                cout << "Enter new last name: ";
                persons[i].setLastName(AuxiliaryMethods::readLine());
                persons[i].setLastName(AuxiliaryMethods::changeFirstLetterToUpperAndRestLettersToLower(persons[i].getLastName()));
                modifySelectedPersonData(persons[i]);
                break;
            case '3':
                cout << "Enter new phone number: ";
                persons[i].setPhoneNumber(AuxiliaryMethods::readLine());
                modifySelectedPersonData(persons[i]);
                break;
            case '4':
                cout << "Enter new email: ";
                persons[i].setEmail(AuxiliaryMethods::readLine());
                modifySelectedPersonData(persons[i]);
                break;
            case '5':
                cout << "Enter new address: ";
                persons[i].setAddress(AuxiliaryMethods::readLine());
                modifySelectedPersonData(persons[i]);
                break;
            case '6':
                cout << endl << "Return to User Menu" << endl << endl;
                break;
            default:
                cout << endl << "No such Menu option! Return to User Menu." << endl << endl;
                break;
            }
        }
    }
    if (ifPersonExist == false) {
        cout << endl << "Not found such person." << endl << endl;
    }
    system("pause");
}

char PersonManager::selectMenuEditOption() {
    char selectChar;

    cout << endl << "   >>> EDIT MENU <<<   " << endl;
    cout << "---------------------------" << endl;
    cout << "Which data do you want to modify: " << endl;
    cout << "1 - First name" << endl;
    cout << "2 - Last name" << endl;
    cout << "3 - Phone Number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Exit " << endl;
    cout << endl << "Your selection: ";
    selectChar = AuxiliaryMethods::readChar();

    return selectChar;
}

void PersonManager::modifySelectedPersonData(Person person) {

    personsFile.modifySelectedPersonInFile(person);

    cout << endl << "Data have been successfully modified." << endl << endl;
}
