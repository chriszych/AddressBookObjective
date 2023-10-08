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
void Person::setFirstName(string firstName) {
    this -> firstName = firstName;
}
void Person::setLastName(string lastName) {
    this -> lastName = lastName;
}
void Person::setPhoneNumber(string phoneNumber) {
    this -> phoneNumber = phoneNumber;
}
void Person::setEmail(string email) {
    this -> email = email;
}
void Person::setAddress(string address) {
    this -> address = address;
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
