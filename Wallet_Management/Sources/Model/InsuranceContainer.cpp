//
// Created by gvice on 13/05/2024.
//

#include "InsuranceContainer.h"
#include "DuplicatedDataException.h"

// Get a list of all insurances
list<Insurance> InsuranceContainer::getAll() {
    return insurances;
}

// Get a specific insurance by its name
Insurance* InsuranceContainer::get(const string& name) {
    list<Insurance>::iterator it = search(name);
    if (it != insurances.end()) {
        return &(*it); // Return a pointer to the Insurance object
    } else {
        return nullptr; // Insurance not found
    }
}

// Add a new insurance to the container
void InsuranceContainer::add(const Insurance& obj) {
    if (search(obj.getName()) == insurances.end()) {
        insurances.push_back(obj);
    } else {
        throw DuplicatedDataException("Insurance with that name already exists");
    }
}

// Remove an insurance by its name
void InsuranceContainer::remove(const string& name) {
    list<Insurance>::iterator it = search(name);
    if (it != insurances.end()) {
        insurances.erase(it);
    }
}

// Update the information of an existing insurance
void InsuranceContainer::update(const string& name, float price, float length) {
    list<Insurance>::iterator it = search(name);
    if (it != insurances.end()) {
        it->setPrice(price);
        it->setLength(length);
    }
}

// Check if an insurance with a specific name already exists
bool InsuranceContainer::isThereInsurance(const string& name) {
    return search(name) != insurances.end();
}

// Search for an insurance by its name
list<Insurance>::iterator InsuranceContainer::search(const string& name) {
    for (list<Insurance>::iterator it = insurances.begin(); it != insurances.end(); ++it) {
        if (it->getName() == name) {
            return it;
        }
    }
    return insurances.end(); // Insurance not found
}