#ifndef WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
#define WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H

#include <list>
#include "Accounts.h"

class AccountsContainers {
private:
    std::list<Accounts> accounts;
    int nextAccountNumber = 1; // Start from a non-zero value


public:
    AccountsContainers() : nextAccountNumber(1) {} // Initialize in the constructor
    list<Accounts> getAll();
    Accounts* get(int nr);
    ~AccountsContainers(); // Declaration only
    void add(const Accounts &obj);
    void remove(int nr);
    void update(int nr, float balance);
    void setBalance(float &balance);


};

#endif //WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H