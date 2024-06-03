//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H
#define WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H

#include <list>
#include "Transactions.h"

using namespace std;

class TransactionsContainers {
private:
    list<Transactions> transactions;

public:
    // Get all transactions in the container
    list<Transactions> getAll();

    // Get transactions associated with a specific account
    list<Transactions> getTransactionsForAccount(Accounts* account);

    // Add a new transaction to the container
    void add(const Transactions& transaction);

    // Remove a transaction from the container (consider adding a unique ID to Transactions)
    void remove(const Transactions& transactionToRemove);
};

#endif //WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H