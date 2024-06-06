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
    // Default Constructor
    Loans() = default;

    // Constructor: Takes the loan type, amount, interest rate, and duration as parameters
    Loans(const string& type, float amount, float interestRate, int durationMonths);

    // Copy Constructor
    Loans(const Loans &obj);

    // Destructor
    ~Loans();

    // Getters
    const string& getType() const;
    float getAmount() const;
    float getInterestRate() const;
    int getDurationMonths() const;

    // Setters (You may want to add validation to these setters)
    void setType(const string& type);
    void setAmount(float amount);
    void setInterestRate(float interestRate);
    void setDurationMonths(int durationMonths);

    // Equality operator: Two loans are considered equal if they have the same type and amount
    bool operator==(const Loans& rhs) const;
};

#endif //WALLET_MANAGEMENT_LOANS_H