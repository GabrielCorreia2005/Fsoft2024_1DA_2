//
// Created by Gabriel on 20/05/2024.
//

#include "Insurance.h"
#include "InvalidDataException.h"

Insurance::Insurance(const string& name, float price, float length, int installments, float fees) : name(name), price(price), length(length), installments(installments), fees(fees) {
    if (price <= 0) {
        throw InvalidDataException("Insurance price must be positive.");
    }
    if (length <= 0) {
        throw InvalidDataException("Insurance length must be positive.");
    }

    if (installments <= 0) {
        throw InvalidDataException("Number of installments must be positive.");
    }

    if (fees < 0) {
        throw InvalidDataException("Fees cannot be negative.");
    }
}

Insurance::Insurance(const Insurance &obj) : name(obj.name), price(obj.price), installments(obj.installments), fees(obj.fees) {}

Insurance::~Insurance() {

}

const string &Insurance::getName() const {
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

void Insurance::setName(const string &name) {
    Insurance::name = name;
}

void Insurance::setPrice(float price) {
    if (price <= 0) {
        throw InvalidDataException("Insurance price must be greater than 0.");
    }
    Insurance::price = price;
}

bool Insurance::operator==(const Insurance &rhs) const {
    return name == rhs.name;
}