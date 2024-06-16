#include "TransactionsView.h"
#include "Utils.h"
#include <iostream>
#include <ctime> // Include for time functions

using namespace std;

Transactions TransactionsView::getTransaction(Client *sourceClient, Client *destinationClient) {
    int transactionId = 1; // Assuming you have a way to generate unique transaction IDs
    Date date = getCurrentDate(); // Use getCurrentDate() to get the current date
    float amount;

    cout << "Enter amount: ";
    cin >> amount;

    // Validate the amount here (e.g., ensure it's positive and within limits)

    // Create the transaction
    Transactions transaction(transactionId, date, amount, sourceClient);
    // Pass sourceAccount to the constructor for tracking

    // You might need additional validation based on your requirements, like:
    // - Checking if the source account has enough balance for the transfer.
    // - Ensuring the type is valid (e.g., "Transfer", "Deposit", "Withdrawal")
    // - ...

    return transaction;
}

// Get the current date
Date TransactionsView::getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
}

void TransactionsView::printTransaction(Transactions *transaction) {
    cout << "Transaction Number: " << transaction->getTransactionId() << endl;
    cout << "Date: " << transaction->getDate() << endl;
    cout << "Amount: " << transaction->getAmount() << endl;
    cout << "Account: " << transaction->getClient()->getNumber() << endl; // Display the source account
}

void TransactionsView::printTransactions(list<Transactions>& transactions) {
    if (transactions.empty()) {
        cout << "No transactions found." << endl;
        return;
    }

    for (Transactions& transaction : transactions) {
        printTransaction(&transaction);
        cout << "---------------------" << endl;
    }
}