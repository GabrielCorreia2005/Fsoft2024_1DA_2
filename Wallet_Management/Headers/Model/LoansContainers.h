//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_LOANSCONTAINERS_H
#define WALLET_MANAGEMENT_LOANSCONTAINERS_H

#include <list>
#include "Loans.h"
#include "DuplicatedDataException.h"

using namespace std;

class LoansContainers {
private:
    list<Loans> loans;
    list<Loans>::iterator search(const string& type, float amount); // Private search function

public:
    // Get a list of all loans
    list<Loans> getAll();

    // Get a specific loan by its type and amount
    // (You might need a more unique identifier for loans)
    Loans* get(const string& type, float amount);

    // Add a new loan to the container
    // Throws a DuplicatedDataException if a loan with the same type and amount already exists
    void add(const Loans& obj);

    // Remove a loan by its type and amount
    void remove(const string& type, float amount);

    // Update the interest rate and duration months of an existing loan
    void update(const string& type, float amount, float interestRate, int durationMonths);

    // Check if a loan with a specific type and amount already exists
    bool isThereLoan(const string& type, float amount);
};


#endif //WALLET_MANAGEMENT_LOANSCONTAINERS_H