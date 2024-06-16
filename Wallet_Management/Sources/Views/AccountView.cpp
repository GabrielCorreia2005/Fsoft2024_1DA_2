#include "AccountView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Accounts AccountView::getAccount(ClientsContainer &clients) {
    int nr;
    float balance;

    // Moved declarations INSIDE the function:
    int accountNumber;
    Client *client;

    // Get account number
    do {
        accountNumber = Utils::getNumber("Account Number");
        if (accountNumber <= 0) {
            cout << "Invalid Account Number. Please enter a positive number." << endl;
        }
    } while (accountNumber <= 0);

    // Get balance (you might want to add validation for positive balance)
    balance = Utils::getNumber("Initial Balance");

    // Select client for the account
    cout << "Select Client for the Account:" << endl;
    list<Client> allClients = clients.getAll();
    int clientCount = 1;
    for (const Client& c : allClients) {
        cout << clientCount << ". " << c.getName() << " (Number: " << c.getNumber() << ")" << endl;
        clientCount++;
    }

    int clientChoice;
    do {
        clientChoice = Utils::getNumber("Enter Client Choice");
        if (clientChoice <= 0 || clientChoice > allClients.size()) {
            cout << "Invalid client choice. Please select from the list." << endl;
        }
    } while (clientChoice <= 0 || clientChoice > allClients.size());

    // Get the chosen client
    auto it = allClients.begin();
    advance(it, clientChoice - 1); // Move the iterator to the chosen client
    client = &(*it); // Get a pointer to the chosen client

    // Now the variables are in scope:
    bool validInput = false;
    do {
        cout << "Enter initial balance: ";
        if (cin >> balance) {
            try {
                // Declare accountNumber and client first
                // You were trying to use them before declaration
                Accounts account(accountNumber, balance, client);
                validInput = true;
                return account;
            } catch (InvalidDataException& e) {
                cerr << "Error: " << e.what() << endl;
            }
        } else {
            cerr << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);

    // This line should never be reached due to the return statement in the try block
    throw runtime_error("An unexpected error occurred during account creation.");
}

// Function to print the details of a single account
void AccountView::printAccount(Accounts *account) {
    if (account) {
        cout << "Account Number: " << account->getNr() << endl;
        cout << "Balance: " << fixed << setprecision(2) << account->getBalance() << endl; // Assuming you have a getBalance() method in Accounts
        cout << "Client: " << account->getClient()->getName() << endl; // Assuming you have getClient() and getName() methods
    } else {
        cout << "Invalid Account (nullptr)" << endl;
    }
}

// Function to print a list of accounts
void AccountView::printAccounts(list<Accounts> &accounts) {
    if (accounts.empty()) {
        cout << "There are no accounts to display." << endl;
        return;
    }

    cout << "List of Accounts:" << endl;
    for (const Accounts& account : accounts) {
        printAccount(const_cast<Accounts *>(&account));
        cout << "--------------------" << endl;
    }
}

void AccountView::printStudentAccounts(Client *client, list<tuple<Accounts *, int>> &subjects) {
    // TODO: Implement this function to print accounts associated with a specific client
}
