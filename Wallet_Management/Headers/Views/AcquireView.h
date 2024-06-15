//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_ACQUIREVIEW_H
#define FSOFT_PROJECT_ACQUIREVIEW_H

#include "Acquire.h"
#include "InsuranceContainer.h"
#include "LoansContainers.h"

class AcquireView {
public:
    // Get Acquire data from the user (insurance and/or loan)
    Acquire getAcquire(InsuranceContainer &insurances, LoansContainers &loans);

    // Print the details of a single Acquire object
    void printAcquire(Acquire *acquire);

    Insurance getInsuranceOnly(InsuranceContainer &insurances);
    Loans getLoanOnly(LoansContainers &loans);

    // void printAcquires(list<Acquire>& acquires); // To print a list of Acquire objects
};

#endif //FSOFT_PROJECT_ACQUIREVIEW_H
