//
// Created by gvice on 13/05/2024.
//

#include "AccountsContainers.h"
#include "DuplicatedDataException.h"

list<Accounts> AccountsContainers::getAll() {
    return accounts;
}

Accounts* AccountsContainers::get(int nr) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getNr() == nr) {
            return &(*it); // Return a pointer to the found Account object
        }
    }
    return nullptr; // Return nullptr if no account with the given number is found
}

void AccountsContainers::add(const Accounts& obj) {
    // Example using a static counter for account numbers:
    static int nextAccountNumber = 1; // Start from 1 or a suitable initial value

    // Assign a unique ID to the new account
    Accounts newAccount(nextAccountNumber++, obj.getBalance(), obj.getClient()); // Assuming a constructor like this exists

    accounts.push_back(newAccount);
}

void AccountsContainers::remove(int nr) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getNr() == nr) {
            accounts.erase(it);
            return; // Account removed, exit the function
        }
    }
    // No account found with the given number
}

void AccountsContainers::update(int nr, float balance) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getNr() == nr) {
            it->setBalance(balance); // Assuming setBalance is in Accounts.cpp
            return; // Account updated, exit the function
        }
    }
    // No account found with the given number
}

AccountsContainers::~AccountsContainers() {
    // You might want to clear or deallocate the resources
    // used by the 'accounts' list if necessary.
    accounts.clear(); // Or any other cleanup logic
}

