#include "AccountsContainers.h"
#include <iostream> // For debugging output

using namespace std;

// Get a list of all accounts
list<Accounts> AccountsContainers::getAll() {
    return accounts;
}

// Get a specific account by account number
Accounts* AccountsContainers::get(int nr) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getNr() == nr) {
            return &(*it);
        }
    }
    return nullptr;
}

// Add a new account to the container
void AccountsContainers::add(const Accounts &obj) {
    accounts.push_back(obj);
    cout << "Added Account: Number=" << obj.getNr()
         << ", Balance=" << obj.getBalance()
         << ", Client=" << obj.getClient()->getNumber()
         << endl;
}

// Remove an account by account number
void AccountsContainers::remove(int nr) {
    // Implement removal logic here!
    // This is just a placeholder
}

// Update the balance of an existing account
void AccountsContainers::update(int nr, float balance) {
    // Implement update logic here!
    // This is just a placeholder
}

void AccountsContainers::setBalance(float &balance) {
    // Implement setBalance logic here!
    // This is just a placeholder
}