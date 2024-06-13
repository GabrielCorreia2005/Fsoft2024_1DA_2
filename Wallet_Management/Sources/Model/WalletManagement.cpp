#include "WalletManagement.h"

WalletManagement::WalletManagement() {
}

WalletManagement::WalletManagement(const char *obj) {
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

}