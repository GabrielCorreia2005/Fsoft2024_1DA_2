//
// Created by Gabriel on 20/05/2024.
//

#include "Client.h"
#include "InvalidDataException.h"

// Constructor
Client::Client(const string& name, const Date& birth) : name(name), birth(birth) {
    // Check if the name is valid
    if (!isNameValid(name)) {
        throw InvalidDataException("Invalid client name: " + name);
    }
}

// Copy Constructor
Client::Client(const Client &obj) : name(obj.name), birth(obj.birth) {}

// Destructor
Client::~Client() {}

// Get the client's name
const string& Client::getName() const {
    return name;
}

// Set the client's name
void Client::setName(const string &name) {
    if (!isNameValid(name)) {
        throw InvalidDataException("Invalid client name: " + name);
    }
    this->name = name;
}

// Get the client's number
int Client::getNumber() const {
    return number;
}

// Set the client's number
void Client::setNumber(int number) {
    this->number = number;
}

// Get the client's birth date
const Date& Client::getBirth() const {
    return birth;
}

// Set the client's birth date
void Client::setBirth(const Date &birth) {
    this->birth = birth;
}

// Check if the client's name is valid
bool Client::isNameValid(const string &name) {
    // Name should not be empty and contain only letters and spaces
    if (name.empty()) {
        return false;
    }
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Equality operator
bool Client::operator==(const Client &obj) const {
    return number == obj.number;
}

// Equality operator for comparing with an integer (client number)
bool Client::operator==(int nr) const {
    return number == nr;
}