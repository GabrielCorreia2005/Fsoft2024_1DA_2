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

TransactionsContainers &WalletManagement::getTransactionsContainer() {
    return transactionsContainer;
}
/*
WalletManagement::WalletManagement(const char *obj) {
}



InsuranceContainer &WalletManagement::getInsuranceContainer() {
    return insuranceContainer;
}



void WalletManagement::setDataForConsistency() {

}*/