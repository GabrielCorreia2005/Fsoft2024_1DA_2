// TransactionsView.cpp
#include "TransactionsView.h"
#include "Utils.h"
#include "Date.h" // Include Date.h for date input

Transactions TransactionsView::getTransaction(Accounts *account) {
    int transactionId = Utils::getNumber("Enter Transaction ID: ");
    string type;
    do {
        type = Utils::getString("Enter Transaction Type (deposit/withdrawal): ");
        if (type != "deposit" && type != "withdrawal") {
            cout << "Invalid transaction type. Please enter 'deposit' or 'withdrawal'." << endl;
        }
    } while (type != "deposit" && type != "withdrawal");

    float amount = Utils::getNumber("Enter Amount: ");
    Date date = Date(Utils::getNumber("Enter Day: "), Utils::getNumber("Enter Month: "), Utils::getNumber("Enter Year: "));

    return Transactions(transactionId, date, type, amount, account);
}

void TransactionsView::printTransaction(Transactions *transaction) {
    cout << "Transaction ID: " << transaction->getTransactionId() << endl;
    cout << "Date: " << transaction->getDate() << endl;
    cout << "Type: " << transaction->getType() << endl;
    cout << "Amount: " << transaction->getAmount() << endl;
    cout << "Account: " << transaction->getAccount()->getNr() << endl;
}

void TransactionsView::printTransactions(list<Transactions>& transactions) {
    if (transactions.empty()) {
        cout << "No transactions found." << endl;
        return;
    }
    for (Transactions& transaction : transactions) {
        printTransaction(&transaction);
        cout << "-------------------------" << endl;
    }
}