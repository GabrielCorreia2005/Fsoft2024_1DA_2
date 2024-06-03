//
// Created by Gabriel on 20/05/2024.
//

#include "Insurance.h"
#include "InvalidDataException.h"

Insurance::Insurance(const string& name, float price) : name(name), price(price) {
    if (price <= 0) {
        throw InvalidDataException("Insurance price must be greater than 0.");
    }
}

Insurance::Insurance(const Insurance &obj) : name(obj.name), price(obj.price) {}

Insurance::~Insurance() {

}

const string &Insurance::getName() const {
    return name;
}

void Insurance::setName(const string &name) {
    Insurance::name = name;
}

float Insurance::getPrice() const {
    return price;
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