#include "WalletManagement.h"


WalletManagement::WalletManagement() {
}

ClientsContainer &WalletManagement::getClientContainer() {
    return clientsContainer;
}

AccountsContainers &WalletManagement::getAccountsContainer() {
    return accountsContainer;
}



/*
WalletManagement::WalletManagement(const char *obj) {
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

}*/