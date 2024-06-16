#ifndef WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
#define WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H

#include <list>
#include "Accounts.h"

using namespace std;

class AccountsContainers {
private:
    list<Accounts> accounts;

public:
    // Get a list of all accounts
    list<Accounts> getAll();

    // Get a specific account by account number (Declaration only)
    Accounts* get(int nr);

    // Add a new account to the container
    void add(const Accounts &obj); // Corrected to use Accounts

    // Remove an account by account number
    void remove(int nr);

    // Update the balance of an existing account
    void update(int nr, float balance);

    void setBalance(float &balance);
};

#endif //WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H