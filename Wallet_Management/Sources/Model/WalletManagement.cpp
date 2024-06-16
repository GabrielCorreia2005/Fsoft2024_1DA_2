#include "WalletManagement.h"
#include "ClientsContainer.h"
#include "AccountsContainers.h"
#include "LoansContainers.h"
#include "InsuranceContainer.h" // Include the InsuranceContainer header
#include "TransactionsContainers.h"

WalletManagement::WalletManagement() :
        nextAccountNumber(1), // Initialize nextAccountNumber to 1
        clientsContainer(),
        accountsContainer(),
        loansContainer(),
        insuranceContainer(),
        transactionsContainer()
{}

WalletManagement::WalletManagement(const string& name) :
        nextAccountNumber(1), // Initialize nextAccountNumber to 1
        clientsContainer(),
        accountsContainer(),
        loansContainer(),
        insuranceContainer(),
        transactionsContainer()
{
    setName(name);
}

const string WalletManagement::getName() const {
    return name;
}

void WalletManagement::setName(const string &name) {
    this->name = name;
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