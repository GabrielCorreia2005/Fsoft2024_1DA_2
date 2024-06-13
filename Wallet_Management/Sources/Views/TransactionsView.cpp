#include "TransactionsView.h"
#include "Utils.h"

Transactions TransactionsView::getTransaction(AccountsContainers &accounts) {
    float amount = Utils::getNumber("Enter transaction amount:");
    string type;
    Date date;
    Accounts *originAccount = nullptr;
    Accounts *destinationAccount = nullptr;

    do {
        cout << "Enter transaction type (Deposit, Withdrawal, Transfer): ";
        cin >> type;
        if (type != "Deposit" && type != "Withdrawal" && type != "Transfer") {
            cout << "Invalid transaction type. Please enter Deposit, Withdrawal, or Transfer." << endl;
        }
    } while (type != "Deposit" && type != "Withdrawal" && type != "Transfer");

    int day, month, year;
    cout << "Enter transaction date (day month year): ";
    cin >> day >> month >> year;
    date.setDate(day, month, year);

    if (type == "Transfer") {
        originAccount = selectOriginAccount(accounts);
        if (originAccount != nullptr) {
            destinationAccount = selectDestinationAccount(accounts, originAccount);
        }
    } else { // Deposit or Withdrawal
        originAccount = selectOriginAccount(accounts);
    }

    return Transactions(amount, type, date, originAccount, destinationAccount);
}

Accounts* TransactionsView::selectOriginAccount(AccountsContainers &accounts) {
    list<Accounts> allAccounts = accounts.getAll();
    if (allAccounts.empty()) {
        cout << "No accounts available." << endl;
        return nullptr;
    }

    cout << "Select Origin Account:" << endl;
    int accountCount = 1;
    for (const Accounts &a : allAccounts) {
        cout << accountCount << ". Account Number: " << a.getNr()
             << " (Client: " << a.client->getName() << ")" << endl;
        accountCount++;
    }

    int choice;
    do {
        choice = Utils::getNumber("Enter the account number: ");
        if (choice <= 0 || choice > allAccounts.size()) {
            cout << "Invalid account number. Please enter a valid number." << endl;
        }
    } while (choice <= 0 || choice > allAccounts.size());

    auto it = allAccounts.begin();
    advance(it, choice - 1);
    return &(*it); // Return a pointer to the selected account
}

Accounts* TransactionsView::selectDestinationAccount(AccountsContainers &accounts, Accounts *originAccount) {
    list<Accounts> allAccounts = accounts.getAll();
    if (allAccounts.size() <= 1) {
        cout << "Not enough accounts for a transfer." << endl;
        return nullptr;
    }

    cout << "Select Destination Account (different from origin):" << endl;
    int accountCount = 1;
    for (const Accounts &a : allAccounts) {
        if (&a != originAccount) { // Don't show the origin account as an option
            cout << accountCount << ". Account Number: " << a.getNr()
                 << " (Client: " << a.client->getName() << ")" << endl;
            accountCount++;
        }
    }

    int choice;
    do {
        choice = Utils::getNumber("Enter the account number: ");

        // Check if the choice is valid (within range and not the origin account)
        if (choice <= 0 || choice >= accountCount ||
            (choice == (std::distance(allAccounts.begin(), std::find(allAccounts.begin(), allAccounts.end(), *originAccount)) + 1))) {
            cout << "Invalid account number. Please enter a valid number different from the origin account." << endl;
        }

    } while (choice <= 0 || choice >= accountCount ||
             (choice == (std::distance(allAccounts.begin(), std::find(allAccounts.begin(), allAccounts.end(), *originAccount)) + 1)));

    auto it = allAccounts.begin();
    int validChoiceCount = 1;
    for (; it != allAccounts.end(); ++it, ++validChoiceCount) {
        if (&(*it) != originAccount && validChoiceCount == choice) {
            break;
        }
    }
    return &(*it); // Return a pointer to the selected account
}


void TransactionsView::printTransaction(Transactions *transaction) {
    cout << "=== Transaction Details ===" << endl;
    cout << "Amount: " << transaction->getAmount() << endl;
    cout << "Type: " << transaction->getType() << endl;
    int day, month, year;
    transaction->getDate().getDate(day, month, year);
    cout << "Date: " << day << "/" << month << "/" << year << endl;

    if (transaction->getOriginAccount() != nullptr) {
        cout << "Origin Account: " << transaction->getOriginAccount()->getNr() << endl;
    }

    if (transaction->getDestinationAccount() != nullptr) {
        cout << "Destination Account: " << transaction->getDestinationAccount()->getNr() << endl;
    }

    cout << "==========================" << endl;
}

void TransactionsView::printTransactions(list<Transactions> &transactions) {
    cout << "=== List of Transactions ===" << endl;
    for (const Transactions& transaction : transactions) {
        printTransaction(&transaction);
    }
    cout << "===========================" << endl;
}

void TransactionsView::printAccountTransactions(Accounts *account, list<Transactions> &transactions) {
    cout << "=== Transactions for Account: " << account->getNr() << " ===" << endl;
    for (const Transactions& transaction : transactions) {
        if (transaction.getOriginAccount() == account || transaction.getDestinationAccount() == account) {
            printTransaction(&transaction);
        }
    }
    cout << "===================================" << endl;
}

Transactions* TransactionsView::selectTransaction(list<Transactions>& transactions) {
    if (transactions.empty()) {
        cout << "No transactions available." << endl;
        return nullptr;
    }

    cout << "=== Select a Transaction ===" << endl;
    int count = 1;
    for (const Transactions &t : transactions) {
        cout << count << ". " << t.getType() << " (Amount: " << t.getAmount() << " on "
             << t.getDate().getDay() << "/" << t.getDate().getMonth() << "/" << t.getDate().getYear() << ")" << endl;
        count++;
    }

    int choice;
    do {
        choice = Utils::getNumber("Enter your choice (number): ");
        if (choice <= 0 || choice > transactions.size()) {
            cout << "Invalid choice. Please enter a valid transaction number." << endl;
        }
    } while (choice <= 0 || choice > transactions.size());

    auto it = transactions.begin();
    advance(it, choice - 1);
    return &(*it); // Return a pointer to the selected transaction
}