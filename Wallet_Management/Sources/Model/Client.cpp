#include "Client.h"
#include <iostream>
#include <regex> // Include the regular expressions library
#include <ctime>

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

bool Client::isNameValid(const string& name) {
    // Check for minimum length (3 characters)
    if (name.length() < 3) {
        cout << "Invalid name. Name must be at least 3 characters long." << endl;
        return false;
    }

    // Check for maximum length (100 characters)
    if (name.length() > 100) {
        cout << "Invalid name. Name must be no more than 100 characters long." << endl;
        return false;
    }

    // Regular expression for allowing letters, spaces, and common accents
    regex namePattern("^[a-zA-Z\\sáàâãäåçéèêëíìîïñóòôõöúùûüýÿÁÀÂÃÄÅÇÉÈÊËÍÌÎÏÑÓÒÔÕÖÚÙÛÜÝ]+$");

    // Check if the name matches the pattern
    if (!regex_match(name, namePattern)) {
        cout << "Invalid name. Name can only contain letters, spaces, and common accents." << endl;
        return false;
    }

    return true; // Name is valids
}




bool Client::operator==(const Client &obj) const {
    return (number == obj.number);
}

bool Client::operator==(int nr) const {
    return (number == nr);
}