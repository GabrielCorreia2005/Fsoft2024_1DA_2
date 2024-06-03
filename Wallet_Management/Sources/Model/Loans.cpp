//
// Created by corre on 20/05/2024.
//

#include "Loans.h"
#include "InvalidDataException.h"

Loans::Loans(const string& type, float amount, float interestRate, int durationMonths)
        : type(type), amount(amount), interestRate(interestRate), durationMonths(durationMonths) {
    if (amount <= 0) {
        throw InvalidDataException("Loan amount must be greater than 0.");
    }
    if (interestRate < 0) {
        throw InvalidDataException("Interest rate cannot be negative.");
    }
    if (durationMonths <= 0) {
        throw InvalidDataException("Loan duration must be greater than 0 months.");
    }
}

Loans::Loans(const Loans &obj)
        : type(obj.type), amount(obj.amount), interestRate(obj.interestRate), durationMonths(obj.durationMonths) {}

Loans::~Loans() {}

const string& Loans::getType() const {
    return type;
}

void Loans::setType(const string& type) {
    Loans::type = type;
}

float Loans::getAmount() const {
    return amount;
}

void Loans::setAmount(float amount) {
    if (amount <= 0) {
        throw InvalidDataException("Loan amount must be greater than 0.");
    }
    Loans::amount = amount;
}

float Loans::getInterestRate() const {
    return interestRate;
}

void Loans::setInterestRate(float interestRate) {
    if (interestRate < 0) {
        throw InvalidDataException("Interest rate cannot be negative.");
    }
    Loans::interestRate = interestRate;
}

int Loans::getDurationMonths() const {
    return durationMonths;
}

void Loans::setDurationMonths(int durationMonths) {
    if (durationMonths <= 0) {
        throw InvalidDataException("Loan duration must be greater than 0 months.");
    }
    Loans::durationMonths = durationMonths;
}

bool Loans::operator==(const Loans& rhs) const {
    return type == rhs.type && amount == rhs.amount;
}

