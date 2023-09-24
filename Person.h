#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person {

    int id;
    int userId;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string address;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int getId();
    int getUserId();
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};
#endif
