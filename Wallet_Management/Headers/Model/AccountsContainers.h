#ifndef WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
#define WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H

#include <list>
#include "Accounts.h"

class AccountsContainers {
private:
    list<Accounts> accounts;

public:
    list<Accounts> getAll();
    Accounts* get(int nr); // Declaration ONLY - No function body here
    void add(const Accounts &obj);
    void remove(int nr);
    void update(int nr, float balance);
    void setBalance(float &balance);
};

#endif //WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H