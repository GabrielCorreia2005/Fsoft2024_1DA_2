//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_ACCOUNTVIEW_H
#define FSOFT_PROJECT_ACCOUNTVIEW_H

#include <list>
#include <tuple>
#include "Accounts.h"
#include "ClientsContainer.h"

class AccountView {
public:
    // Get account data from the user
    Accounts getAccount(ClientsContainer &clients);

    // Print details of a single account
    void printAccount(Accounts *account);

    // Print a list of accounts
    void printAccounts(list<Accounts>& accounts);

    // Print accounts associated with a specific client (To be implemented based on your requirements)
    void printStudentAccounts(Client *client, list<tuple<Accounts *, int>> &subjects);
};

#endif //FSOFT_PROJECT_ACCOUNTVIEW_H