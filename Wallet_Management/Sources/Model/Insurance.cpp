#include "Insurance.h"

Insurance::Insurance(const string &name, float price, float length, int installments, float fees, Client* client)
        : name(name), price(price), length(length), installments(installments), fees(fees), client(client) {
    if (!isNameValid(name)) {
        throw InvalidDataException("Invalid Insurance name.");
    }
}

Insurance::Insurance(const Insurance &obj)
        : name(obj.name), price(obj.price), length(obj.length),
          installments(obj.installments), fees(obj.fees), client(obj.client) {}

Insurance::~Insurance() {}

const string& Insurance::getName() const {
    return name;
}

float Insurance::getPrice() const {
    return price;
}

float Insurance::getLength() const {
    return length;
}

int Insurance::getInstallments() const {
    return installments;
}

float Insurance::getFees() const {
    return fees;
}

Client* Insurance::getClient() const {
    return client;
}

void Insurance::setName(const string &name) {
    if (isNameValid(name)) {
        Insurance::name = name;
    } else {
        throw InvalidDataException("Invalid Insurance name.");
    }
}

void Insurance::setPrice(float price) {
    Insurance::price = price;
}

void Insurance::setLength(float length) {
    Insurance::length = length;
}

void Insurance::setInstallments(int installments) {
    Insurance::installments = installments;
}

void Insurance::setFees(float fees) {
    Insurance::fees = fees;
}

void Insurance::setClient(Client *client) {
    Insurance::client = client;
}

bool Insurance::operator==(const Insurance &rhs) const {
    return name == rhs.name;
}

bool Insurance::isNameValid(const string &name) {
    // Add your validation logic for the insurance name here
    // For example, check if the name is not empty, meets certain length requirements, etc.
    return !name.empty();
}