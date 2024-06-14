//
// Created by gvice on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_LOANS_H
#define WALLET_MANAGEMENT_LOANS_H

#include <string>
#include <list> // Add this line
#include "InvalidDataException.h"

using namespace std;

class Loans {
private:
    int number;
    string type;
    float amount;
    float interestRate;
    int durationMonths;

public:
    Loans(int number, const string& type, float amount, float interestRate, int durationMonths);
    Loans(const Loans &obj);
    ~Loans();

    const string& getType() const;
    void setType(const string& type);

    float getAmount() const;
    void setAmount(float amount);

    float getInterestRate() const;
    void setInterestRate(float interestRate);

    int getDurationMonths() const;
    void setDurationMonths(int durationMonths);

    bool operator==(const Loans& rhs) const;
};

#endif //WALLET_MANAGEMENT_LOANS_H H