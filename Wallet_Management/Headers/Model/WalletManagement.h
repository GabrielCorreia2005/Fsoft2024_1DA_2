#ifndef WALLET_MANAGEMENT_WALLETMANAGEMENT_H
#define WALLET_MANAGEMENT_WALLETMANAGEMENT_H

#include "ClientsContainer.h"
#include "AccountsContainers.h"
#include "LoansContainers.h"
#include "InsuranceContainer.h"
#include "TransactionsContainers.h"

class WalletManagement {
private:
    string name;
    int nextAccountNumber; // Added to track the next account number
    ClientsContainer clientsContainer;
    AccountsContainers accountsContainer;
    LoansContainers loansContainer;
    TransactionsContainers transactionsContainer;

public:
    // Constructors
    WalletManagement();
    WalletManagement(const string& name);

    const string getName() const;
    void setName(const string &name);

    ClientsContainer &getClientContainer();
    AccountsContainers &getAccountsContainer();
    LoansContainers &getLoansContainer();
    TransactionsContainers &getTransactionsContainer();

    int getNextAccountNumber(); // Added to get the next unique account number
};

#endif //WALLET_MANAGEMENT_WALLETMANAGEMENT_H
