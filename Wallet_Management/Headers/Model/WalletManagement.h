//
// Created by Gabriel on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_WALLETMANAGEMENT_H
#define WALLET_MANAGEMENT_WALLETMANAGEMENT_H

#include "ClientsContainer.h"
#include "AccountsContainers.h"
#include "LoansContainers.h"
#include "InsuranceContainer.h"
#include "TransactionsContainers.h"

class WalletManagement {
private:
    ClientsContainer clientsContainer;
    AccountsContainers accountsContainer;
    LoansContainers loansContainer;
    InsuranceContainer insuranceContainer;
    TransactionsContainers transactionsContainer;

    void setDataForConsistency(); // Function to check and enforce data consistency

public:
    // Constructors
    WalletManagement();
    WalletManagement(const WalletManagement &obj);

    // Getters for the containers
    ClientsContainer &getClientContainer();
    AccountsContainers &getAccountsContainer();
    LoansContainers &getLoansContainer();
    InsuranceContainer &getInsuranceContainer();
    TransactionsContainers &getTransactionsContainer();

 //por adicionar mais
};

#endif //WALLET_MANAGEMENT_WALLETMANAGEMENT_H