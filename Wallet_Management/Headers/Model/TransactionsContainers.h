// TransactionsContainers.h
#ifndef WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H
#define WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H

#include <list>
#include "Transactions.h"

using namespace std;

class TransactionsContainers {
private:
    list<Transactions> transactions;
    list<Transactions>::iterator search(int transactionId); // Search by transaction ID

public:
    // Get all transactions
    list<Transactions> getAll();

    // Get a single transaction by its ID
    Transactions* get(int transactionId);

    // Add a new transaction to the container
    void add(const Transactions& obj);

    // Remove a transaction by its ID
    void remove(int transactionId);

    // Update a transaction (You might not need this, but it's possible)
    void update(int transactionId, const Date& date, const string& type, float amount, Accounts *account);
};

#endif //WALLET_MANAGEMENT_TRANSACTIONSCONTAINERS_H