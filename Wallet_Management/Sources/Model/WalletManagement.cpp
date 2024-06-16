#include "WalletManagement.h"

WalletManagement::WalletManagement() : nextAccountNumber(1) {}

WalletManagement::WalletManagement(const string& name) : name(name), nextAccountNumber(1) {}

const string WalletManagement::getName() const {
    return name;
}

void WalletManagement::setName(const string &name) {
    WalletManagement::name = name;
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

int WalletManagement::getNextAccountNumber() {
    return nextAccountNumber++;
}