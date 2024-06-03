//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACQUIRE_H
#define WALLET_MANAGEMENT_ACQUIRE_H

#include "Insurance.h"
#include "Loans.h"
#include "InvalidDataException.h"

class Acquire {
private:
    Insurance insurance;
    Loans loans;
    bool isPointerNotNull(void * pointer);

public:
    Acquire(Insurance insurance, Loansloans);
    Acquire(const Acquire &obj);
    ~Acquire();

    Insurance getInsurance() const;
    void setInsurance(Insuranceinsurance);

    Loans getLoans() const;
    void setLoans(Loansloans);

    bool operator==(const Acquire &rhs) const;
};


#endif //WALLET_MANAGEMENT_ACQUIRE_H

