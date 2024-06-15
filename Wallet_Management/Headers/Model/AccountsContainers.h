//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
#define WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H

#include <list>
#include "Accounts.h"

class AccountsContainers {
private:
    list<Accounts> accounts;

public:
    list<Accounts> getAll();
    Accounts* get(int nr); // Declaration only
    void add(const Accounts &obj);
    void remove(int nr); // Remove account by account number
    void update(int nr, float balance);
    void setBalance(float &balance);
};

#endif //WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H