//
// Created by corre on 20/05/2024.
//

#include "WalletManagement.h"
#include "DataConsistencyException.h"

WalletManagement::WalletManagement()  {
    accountsContainer.setClients(&clientsContainer); // Set up the relationship between containers
    loansContainer.setClients(&clientsContainer);
    insuranceContainer.setClients(&clientsContainer);
    transactionsContainer.setAccounts(&accountsContainer);
}

WalletManagement::WalletManagement(const WalletManagement &obj) :
        clientsContainer(obj.clientsContainer),
        accountsContainer(obj.accountsContainer),
        loansContainer(obj.loansContainer),
        insuranceContainer(obj.insuranceContainer),
        transactionsContainer(obj.transactionsContainer) {
    accountsContainer.setClients(&clientsContainer); // Set up the relationship between containers
    loansContainer.setClients(&clientsContainer);
    insuranceContainer.setClients(&clientsContainer);
    transactionsContainer.setAccounts(&accountsContainer);
}

ClientsContainer &WalletManagement::getClientContainer() {
    return clientsContainer;
}

AccountsContainers &WalletManagement::getAccountsContainer() {
    return accountsContainer;
}

LoansContainers &WalletManagement::getLoansContainer() {
    return loansContainer;
}

InsuranceContainer &WalletManagement::getInsuranceContainer() {
    return insuranceContainer;
}

TransactionsContainers &WalletManagement::getTransactionsContainer() {
    return transactionsContainer;
}

void WalletManagement::setDataForConsistency() {
    // Implement checks for data consistency across containers
}