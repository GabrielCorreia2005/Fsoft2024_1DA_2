//
// Created by gvice on 13/05/2024.
//

#include "TransactionsContainers.h"

// Get all transactions
list<Transactions> TransactionsContainers::getAll() {
    return transactions;
}

// Get transactions for a specific account (either origin or destination)
list<Transactions> TransactionsContainers::getTransactionsForAccount(Accounts* account) {
    list<Transactions> accountTransactions;
    for (const Transactions& transaction : transactions) {
        if (transaction.getOriginAccount() == account || transaction.getDestinationAccount() == account) {
            accountTransactions.push_back(transaction);
        }
    }
    return accountTransactions;
}

// Add a new transaction
void TransactionsContainers::add(const Transactions& transaction) {
    transactions.push_back(transaction);
}

// Remove a transaction (You might need a better way to identify transactions uniquely)
void TransactionsContainers::remove(const Transactions& transactionToRemove) {
    transactions.remove(transactionToRemove);
}
