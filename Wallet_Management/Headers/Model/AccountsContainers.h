//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
#define WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H

#include <list>
#include "Accounts.h"

class AccountsContainer{
private:
    list<Accounts> accounts;
    list<Accounts>::iterator search(int &nr);

public:
    list<Accounts> getAll();
    Instructor* get(int &nr);
    void add(const Accounts& obj);
    void remove(int &nr);
    void update(int nr, float balance, Client * client);
    bool  isThereSubject(int &nr);

};


#endif //WALLET_MANAGEMENT_ACCOUNTSCONTAINERS_H
