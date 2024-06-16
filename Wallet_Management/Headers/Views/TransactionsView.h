// TransactionsView.h
#ifndef WALLET_MANAGEMENT_TRANSACTIONSVIEW_H
#define WALLET_MANAGEMENT_TRANSACTIONSVIEW_H

#include <list>
#include "Transactions.h"

class TransactionsView {
public:
    // Get transaction details from the user
    Transactions getTransaction(Accounts *account); // Account for the transaction

    // Print details of a single transaction
    void printTransaction(Transactions *transaction);

    // Print a list of transactions
    void printTransactions(list<Transactions>& transactions);
};

#endif //WALLET_MANAGEMENT_TRANSACTIONSVIEW_H