#ifndef WALLET_MANAGEMENT_WALLETMANAGEMENT_H
#define WALLET_MANAGEMENT_WALLETMANAGEMENT_H

#include "ClientsContainer.h"
#include "AccountsContainers.h"
#include "LoansContainers.h"
#include "InsuranceContainer.h" // Include the InsuranceContainer header
#include "TransactionsContainers.h"

class WalletManagement {
private:
    string name;
    int nextAccountNumber; // Added to track the next account number
    ClientsContainer clientsContainer;
    AccountsContainers accountsContainer;
    LoansContainers loansContainer;
    InsuranceContainer insuranceContainer; // Add the insuranceContainer member
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
    InsuranceContainer &getInsuranceContainer(); // Add a getter for the insuranceContainer
    TransactionsContainers &getTransactionsContainer();

    int getNextAccountNumber(); // Added to get the next unique account number
};

#endif //WALLET_MANAGEMENT_WALLETMANAGEMENT_H