//
// Created by gvice on 20/05/2024.
//

#include "TransactionsView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

Transactions TransactionsView::getTransaction(AccountsContainers &accounts) {
    float amount;
    string type;
    Date date;
    Accounts *originAccount = nullptr;
    Accounts *destinationAccount = nullptr;

    // Get transaction amount
    do {
        amount = Utils::getNumber("Enter transaction amount: ");
        if (amount <= 0) {
            cout << "Invalid transaction amount. Please enter a positive number." << endl;
        }
    } while (amount <= 0);

    // Get transaction type
    type = Utils::getString("Enter transaction type: ");

    // Get transaction date
    int day, month, year;
    cout << "Enter transaction date (day month year): ";
    cin >> day >> month >> year;
    date.setDate(day, month, year);

    // Get origin account (optional)
    int originChoice;
    do {
        cout << "Does this transaction have an origin account?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        originChoice = Utils::getNumber("Enter your choice: ");

        if (originChoice != 1 && originChoice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (originChoice != 1 && originChoice != 2);

    if (originChoice == 1) {
        cout << "Available Accounts:" << endl;
        list<Accounts> allAccounts = accounts.getAll();
        int accountCount = 1;
        for (const Accounts &a : allAccounts) {
            cout << accountCount << ". Account Number: " << a.getNumber()
                 << " (Client: " << a.getClient()->getName() << ")" << endl;
            accountCount++;
        }

        int accountSelection;
        do {
            accountSelection = Utils::getNumber("Select Origin Account (enter number): ");
            if (accountSelection <= 0 || accountSelection > allAccounts.size()) {
                cout << "Invalid account selection." << endl;
            }
        } while (accountSelection <= 0 || accountSelection > allAccounts.size());

        auto accountIt = allAccounts.begin();
        advance(accountIt, accountSelection - 1);
        originAccount = &(*accountIt);
    }

    // Get destination account (optional)
    int destinationChoice;
    do {
        cout << "Does this transaction have a destination account?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        destinationChoice = Utils::getNumber("Enter your choice: ");

        if (destinationChoice != 1 && destinationChoice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (destinationChoice != 1 && destinationChoice != 2);

    if (destinationChoice == 1) {
        cout << "Available Accounts:" << endl;
        list<Accounts> allAccounts = accounts.getAll();
        int accountCount = 1;
        for (const Accounts &a : allAccounts) {
            cout << accountCount << ". Account Number: " << a.getNumber()
                 << " (Client: " << a.getClient()->getName() << ")" << endl;
            accountCount++;
        }

        int accountSelection;
        do {
            accountSelection = Utils::getNumber("Select Destination Account (enter number): ");
            if (accountSelection <= 0 || accountSelection > allAccounts.size()) {
                cout << "Invalid account selection." << endl;
            }
        } while (accountSelection <= 0 || accountSelection > allAccounts.size());

        auto accountIt = allAccounts.begin();
        advance(accountIt, accountSelection - 1);
        destinationAccount = &(*accountIt);
    }

    return Transactions(amount, type, date, originAccount, destinationAccount);
}


void TransactionsView::printTransaction(Transactions *transaction) {
    if (transaction) {
        cout << "Transaction Type: " << transaction->getType() << endl;
        cout << "Amount: " << fixed << setprecision(2) << transaction->getAmount() << endl;
        cout << "Date: ";
        int day, month, year;
        transaction->getDate().getDate(day, month, year);
        cout << day << "/" << month << "/" << year << endl;

        if (transaction->getOriginAccount()) {
            cout << "Origin Account: " << transaction->getOriginAccount()->getNumber() << endl;
        }
        if (transaction->getDestinationAccount()) {
            cout << "Destination Account: " << transaction->getDestinationAccount()->getNumber() << endl;
        }
    } else {
        cout << "Invalid Transaction (nullptr)." << endl;
    }
}

void TransactionsView::printTransactions(list<Transactions> &transactions) {
    if (transactions.empty()) {
        cout << "There are no transactions to display." << endl;
        return;
    }

    cout << "List of Transactions:" << endl;
    for (const Transactions &transaction : transactions) {
        printTransaction(&transaction);
        cout << "--------------------" << endl;
    }
}