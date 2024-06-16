#ifndef WALLET_MANAGEMENT_ACQUIREVIEW_H
#define WALLET_MANAGEMENT_ACQUIREVIEW_H

#include <list>
#include "Acquire.h"
#include "Client.h"
#include "Insurance.h"
#include "InsuranceContainer.h"
#include "ClientsContainer.h"

class AcquireView {
public:
    // Get acquire details from the user
    Acquire getAcquire(ClientsContainer &clients, InsuranceContainer &insurances);

    // Print details of a single acquire
    void printAcquire(Acquire *acquire);

    // Print a list of acquires
    void printAcquires(list<Acquire> &acquires);
};

#endif //WALLET_MANAGEMENT_ACQUIREVIEW_H