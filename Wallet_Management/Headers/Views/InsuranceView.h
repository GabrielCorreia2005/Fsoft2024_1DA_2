#ifndef FSOFT_PROJECT_INSURANCEVIEW_H
#define FSOFT_PROJECT_INSURANCEVIEW_H

#include <list>
#include "Insurance.h"
#include "ClientsContainer.h" // Include ClientsContainer for client selection

class InsuranceView {
public:
    Insurance getInsurance(ClientsContainer& clients); // Add ClientsContainer reference
    void printInsurance(Insurance *insurance);
    void printInsurances(list<Insurance> &insurances);
};

#endif //FSOFT_PROJECT_INSURANCEVIEW_H