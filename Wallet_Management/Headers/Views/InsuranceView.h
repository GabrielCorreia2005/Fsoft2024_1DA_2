//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_INSURANCEVIEW_H
#define FSOFT_PROJECT_INSURANCEVIEW_H

#include <list>
#include "Insurance.h"

class InsuranceView {
public:
    // Get insurance data from user input
    Insurance getInsurance();

    // Print the details of a single insurance policy
    void printInsurance(Insurance insurance);

    // Print a list of insurance policies
    void printInsurances(list<Insurance> &insurances);

    // You might want to add functions like:
    // void printClientInsurances(Clientclient, list<Insurance> &insurances); // To print insurances for a specific client
    // Insurance* selectInsurance(list<Insurance> &insurances); // To allow the user to select an insurance from a list
};

#endif //FSOFT_PROJECT_INSURANCEVIEW_H