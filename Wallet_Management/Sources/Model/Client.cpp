#include "Client.h"
#include <iostream>
#include "InvalidDataException.h"
#include "ClientsContainer.h" // Add this include

using namespace std;

Client::Client(const string &name, const Date &birth, const int number) : //  Remove 'number' argument
        name(name), birth(birth)
{
    if(!isNameValid(name)){
        throw InvalidDataException("Name is invalid");
    }
}

Client::Client(const Client &obj) :
        name(obj.name), birth(obj.birth)
{
    // Remove 'number' assignment
}

Client::~Client() {

}

const string& Client::getName() const {
    return name;
}

void Client::setName(const string &name) {
    if(!isNameValid(name)){
        throw InvalidDataException("Name is invalid");
    }
    this->name = name;
}

// Remove getNumber() and setNumber()

const Date& Client::getBirth() const {
    return birth;
}

void Client::setBirth(const Date &birth) {
    this->birth = birth;
}

bool Client::operator==(const Client &obj) const {
    // Compare only the 'name' now
    return (name == obj.name);
}

// Remove operator==(int)

bool Client::isNameValid(const string &name) {
    // Your name validation logic here
    // For example:
    if (name.empty()) {
        return false;
    }
    // Additional checks (e.g., only letters and spaces)
    return true;
}

int ClientsContainer::nextClientNumber = 1; // Now ClientsContainer is known