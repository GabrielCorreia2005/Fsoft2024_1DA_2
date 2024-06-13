//
// Created by gvice on 20/05/2024.
//

#ifndef FSOFT_PROJECT_TRANSACTIONSVIEW_H
#define FSOFT_PROJECT_TRANSACTIONSVIEW_H

#include <list>
#include "Transactions.h"
#include "AccountsContainers.h" // To access account information

class TransactionsView {
public:
    // Get transaction data from the user
    Transactions getTransaction(AccountsContainers &accounts);

    // Print the details of a single transaction
    void printTransaction(Transactions *transaction);

    // Print a list of transactions
    void printTransactions(list<Transactions> &transactions);

    void printAccountTransactions(Accounts* account, list<Transactions>& transactions); // To print transactions for a specific account
    Transactions* selectTransaction(list<Transactions>& transactions); // To allow user to select a transaction from a list
};

#endif //FSOFT_PROJECT_TRANSACTIONSVIEW_H
