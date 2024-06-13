#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(const string &name, const Date &birth):
        name(name), birth(birth), number(0) { // Initialize number here!
    if (!isNameValid(name))
        throw InvalidDataException("The name is invalid, you need to use only letters.");
    // ... (other initialization or validation logic if needed) ...
}

Client::Client(const Client &obj) {
    this->name = obj.name;
    this->number = obj.number;
    this->birth = obj.birth;
}

Client::~Client() = default;

const string &Client::getName() const {
    return name;
}

void Client::setName(const string &name) {
    if (!isNameValid(name))
        throw InvalidDataException("The name is invalid, you need to use only letters.");
    Client::name = name;
}

int Client::getNumber() const {
    return number;
}

void Client::setNumber(int number) {
    Client::number = number;
}

const Date &Client::getBirth() const {
    return birth;
}

void Client::setBirth(const Date &birth) {
    Client::birth = birth;
}

bool Client::isNameValid(const string &name) {
    for (char c: name) {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

bool Client::operator==(const Client &obj) const {
    return (number == obj.number);
}

bool Client::operator==(int nr) const {
    return (number == nr);
}