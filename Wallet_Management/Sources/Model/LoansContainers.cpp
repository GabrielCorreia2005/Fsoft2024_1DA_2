//
// Created by Gabriel on 13/05/2024.
//

#include "LoansContainers.h"
#include "DuplicatedDataException.h"

// Get a list of all loans
list<Loans> LoansContainers::getAll() {
    return loans;
}

Loans* LoansContainers::getsingle(int number) {

    if (loansmap.find(number) != loansmap.end()) {
        return loansmap[number]; // Return a pointer to the Loans object
    } else {
        return nullptr; // Loan not found
    }
}
// Get a specific loan by its type and amount (you might need a more unique identifier)
Loans* LoansContainers::get(const string& type, float amount) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        return &(*it); // Return a pointer to the Loans object
    } else {
        return nullptr; // Loan not found
    }
}

// Add a new loan to the container
void LoansContainers::add(const Loans& obj) {
    if (search(obj.getType(), obj.getAmount()) == loans.end()) {
        loans.push_back(obj);
    } else {
        throw DuplicatedDataException("Loan with that type and amount already exists");
    }
}

// Remove a loan by its type and amount
void LoansContainers::remove(const string& type, float amount) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        loans.erase(it);
    }
}

// Update the information of an existing loan
void LoansContainers::update(const string& type, float amount, float interestRate, int durationMonths) {
    list<Loans>::iterator it = search(type, amount);
    if (it != loans.end()) {
        it->setInterestRate(interestRate);
        it->setDurationMonths(durationMonths);
    }
}

// Check if a loan with a specific type and amount already exists
bool LoansContainers::isThereLoan(const string& type, float amount) {
    return search(type, amount) != loans.end();
}

// Search for a loan by its type and amount
list<Loans>::iterator LoansContainers::search(const string& type, float amount) {
    for (list<Loans>::iterator it = loans.begin(); it != loans.end(); ++it) {
        if (it->getType() == type && it->getAmount() == amount) {
            return it;
        }
    }
    return loans.end(); // Loan not found
}