#ifndef WALLET_MANAGEMENT_TRANSACTIONSVIEW_H
#define WALLET_MANAGEMENT_TRANSACTIONSVIEW_H

#include <list>
#include "Transactions.h"
#include "Accounts.h" // Include the Accounts header

class TransactionsView {
public:
    // Get transaction details from the user
    Transactions getTransaction(Accounts *sourceAccount, Accounts *destinationAccount);

    // Print details of a single transaction
    void printTransaction(Transactions *transaction);

    // Print a list of transactions
    void printTransactions(list<Transactions>& transactions);

    // Declare getCurrentDate() function
    Date getCurrentDate();
};

#endif //WALLET_MANAGEMENT_TRANSACTIONSVIEW_H