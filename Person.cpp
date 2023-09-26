#include "Person.h"

using namespace std;

void Person::setId(int newId) {
    if(newId >= 0) {
        id = newId;
    }
}
void Person::setUserId(int newUserId) {
    if(newUserId >= 0) {
        userId = newUserId;
    }
}
void Person::setFirstName(string newFirstName) {
    firstName = newFirstName;
}
void Person::setLastName(string newLastName) {
    lastName = newLastName;
}
void Person::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}
void Person::setEmail(string newEmail) {
    email = newEmail;
}
void Person::setAddress(string newAddress) {
    address = newAddress;
}

int Person::getId() {
    return id;
}
int Person::getUserId() {
    return userId;
}
string Person::getFirstName() {
    return firstName;
}
string Person::getLastName() {
    return lastName;
}
string Person::getPhoneNumber() {
    return phoneNumber;
}
string Person::getEmail() {
    return email;
}
string Person::getAddress() {
    return address;
}
