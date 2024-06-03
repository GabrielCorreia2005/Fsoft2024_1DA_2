//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_LOANS_H
#define WALLET_MANAGEMENT_LOANS_H

#include <string>
#include "InvalidDataException.h"

using namespace std;

class Loans {
private:
    string type; // The type of loan (e.g., "Personal Loan", "Mortgage")
    float amount; // The principal loan amount
    float interestRate; // The annual interest rate
    int durationMonths; // The duration of the loan in months

public:
    // Constructor: Takes the loan type, amount, interest rate, and duration as parameters
    Loans(const string& type, float amount, float interestRate, int durationMonths);

    // Copy Constructor
    Loans(const Loans &obj);

    // Destructor
    ~Loans();

    // Getters and Setters for the private member variables
    const string& getType() const;
    void setType(const string& type);

    float getAmount() const;
    void setAmount(float amount); // Throws an exception if the amount is not positive

    float getInterestRate() const;
    void setInterestRate(float interestRate); // Throws an exception if the rate is negative

    int getDurationMonths() const;
    void setDurationMonths(int durationMonths); // Throws an exception if duration is not positive

    // Equality operator: Two loans are considered equal if they have the same type and amount
    bool operator==(const Loans& rhs) const;
};

#endif //WALLET_MANAGEMENT_LOANS_H