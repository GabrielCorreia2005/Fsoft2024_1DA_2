//
// Created by Gabriel on 20/05/2024.
//

#include "Acquire.h"

Acquire::Acquire(Insurance *insurance, Loans *loans) {
    this->insurance = insurance;
    this->loans = loans;

    if(!isPointerNotNull(insurance) || !isPointerNotNull(loans))
        throw InvalidDataException("The insurance or loan pointer is null");
}

Acquire::Acquire(const Acquire &obj) {
    this->insurance = obj.insurance;
    this->loans = obj.loans;
}

Acquire::~Acquire() {

}

bool Acquire::isPointerNotNull(void *pointer) {
    return pointer != nullptr;
}

Insurance *Acquire::getInsurance() const {
    return insurance;
}

void Acquire::setInsurance(Insurance *insurance) {
    this->insurance = insurance;
}

Loans *Acquire::getLoans() const {
    return loans;
}

void Acquire::setLoans(Loans *loans) {
    this->loans = loans;
}

bool Acquire::operator==(const Acquire &rhs) const {
    return insurance == rhs.insurance &&
           loans == rhs.loans;
}