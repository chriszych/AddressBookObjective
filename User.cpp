#include "User.h"

using namespace std;

void User::setId(int newId) {
    if(newId >= 0) {
        id = newId;
    }
}

void User::setLogin(string login) {
    this -> login = login;
}

void User::setPassword(string password) {
    this -> password = password;
}

int User::getId() {
    return id;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}
