#include "WalletManagement.h"

WalletManagement::WalletManagement() {
    this -> name = "";
}

WalletManagement::WalletManagement(const string& name) {
    this -> name = name;
}

ClientsContainer &WalletManagement::getClientContainer() {
    return clientsContainer;
}

AccountsContainers &WalletManagement::getAccountsContainer() {
    return accountsContainer;
}

void WalletManagement::setName(const string &name)
{
    this ->name = name;
}

LoansContainers &WalletManagement::getLoansContainer() {
    return loansContainer;
}

WalletManagement::~WalletManagement() {
    // Make sure to call the destructors of the containers
    // if they have any resources to clean up.
    // Example:
    clientsContainer.~ClientsContainer();
    accountsContainer.~AccountsContainers();
    loansContainer.~LoansContainers();
}
/*
WalletManagement::WalletManagement(const char *obj) {
}



InsuranceContainer &WalletManagement::getInsuranceContainer() {
    return insuranceContainer;
}

TransactionsContainers &WalletManagement::getTransactionsContainer() {
    return transactionsContainer;
}

void WalletManagement::setDataForConsistency() {

}*/