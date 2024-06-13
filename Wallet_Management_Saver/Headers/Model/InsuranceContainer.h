//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_INSURANCECONTAINER_H
#define WALLET_MANAGEMENT_INSURANCECONTAINER_H

#include <list>
#include "Insurance.h"
#include "DuplicatedDataException.h"

using namespace std;

class InsuranceContainer {
private:
    list<Insurance> insurances;
    list<Insurance>::iterator search(const string& name); // Private search function

public:
    // Get a list of all insurance policies in the container
    list<Insurance> getAll();

    // Get a pointer to an insurance policy by its name
    // Returns nullptr if the insurance is not found
    Insurance* get(const string& name);

    // Add a new insurance policy to the container
    // Throws a DuplicatedDataException if an insurance policy with the same name already exists
    void add(const Insurance& obj);

    // Remove an insurance policy from the container by its name
    void remove(const string& name);

    // Update the price and length of an existing insurance policy in the container
    void update(const string& name, float price, float length);

    // Check if an insurance policy with a given name exists in the container
    bool isThereInsurance(const string& name);
};

#endif //WALLET_MANAGEMENT_INSURANCECONTAINER_H