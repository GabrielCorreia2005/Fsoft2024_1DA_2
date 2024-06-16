#ifndef FSOFT_PROJECT_ACCOUNTVIEW_H
#define FSOFT_PROJECT_ACCOUNTVIEW_H

#include <list>
#include <tuple>
#include "Accounts.h"
#include "ClientsContainer.h"
#include "WalletManagement.h" // Include WalletManagement.h

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

    // Function to print account information (added)
    void printAccountInformation(WalletManagement& walletManagement);
};

#endif //FSOFT_PROJECT_ACCOUNTVIEW_H