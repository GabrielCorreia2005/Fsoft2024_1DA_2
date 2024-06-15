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
    Acquire(Insurance insurance, Loans loans);
    Acquire(const Acquire &obj);
    ~Acquire();

    const Insurance getInsurance() const;
    void setInsurance(Insurance insurance);

    const Loans getLoans() const;

    void setLoans(Loans *loans);

    bool operator==(const Acquire &rhs) const;


    void setInsurance(Insurance *insurance);
};


#endif //WALLET_MANAGEMENT_ACQUIRE_H

