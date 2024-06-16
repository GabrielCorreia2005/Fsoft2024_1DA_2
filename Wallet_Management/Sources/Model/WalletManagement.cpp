#include "WalletManagement.h"

WalletManagement::WalletManagement() : nextAccountNumber(1) { // Initialize nextAccountNumber
    this->name = "";
}

WalletManagement::WalletManagement(const string& name) : nextAccountNumber(1) { // Initialize nextAccountNumber
    this->name = name;
}

ClientsContainer &WalletManagement::getClientContainer() {
    return clientsContainer;
}

AccountsContainers &WalletManagement::getAccountsContainer() {
    return accountsContainer;
}

void WalletManagement::setName(const string &name) {
    this->name = name;
}

LoansContainers &WalletManagement::getLoansContainer() {
    return loansContainer;
}

TransactionsContainers &WalletManagement::getTransactionsContainer() {
    return transactionsContainer;
}

int WalletManagement::getNextAccountNumber() {
    return nextAccountNumber++;
}
