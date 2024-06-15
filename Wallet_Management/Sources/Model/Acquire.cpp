#include "Acquire.h"
#include <iostream>

// Constructor
Acquire::Acquire(Insurance insurance, Loans loans) :
        insurance(insurance), loans(loans) {}

// Copy Constructor
Acquire::Acquire(const Acquire &obj) :
        insurance(obj.insurance), loans(obj.loans) {}

// Destructor
Acquire::~Acquire() {}

// Getters
const Insurance Acquire::getInsurance() const {
    return insurance;
}

const Loans Acquire::getLoans() const {
    return loans;
}

// Setters
void Acquire::setInsurance(Insurance insurance) {
    this->insurance = insurance;
}


// Equality Operator (if needed)
bool Acquire::operator==(const Acquire &rhs) const {
    return (insurance == rhs.insurance && loans == rhs.loans);
}

// isPointerNotNull (helper function)
bool Acquire::isPointerNotNull(void * pointer) {
    return (pointer != nullptr);
}

// Setters with pointers (if needed for dynamic allocation)
void Acquire::setInsurance(Insurance *insurance) {
    if (isPointerNotNull(insurance)) {
        this->insurance = *insurance; // Assign the value pointed to
    } else {
        // Handle the nullptr case (e.g., throw an exception or set a default)
        std::cerr << "Error: Null pointer passed to setInsurance" << std::endl;
    }
}

void Acquire::setLoans(Loans *loans) {
    if (isPointerNotNull(loans)) {
        this->loans = *loans;
    }
}