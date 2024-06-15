//
// Created by gvice on 20/05/2024.
//

#include "AccountView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

Accounts AccountView::getAccount(ClientsContainer &clients) {
    int nr;
    float balance;
    Client *client;

    // Get account number
    do {
        nr = Utils::getNumber("Account Number");
        if (nr <= 0) {
            cout << "Invalid Account Number. Please enter a positive number." << endl;
        }
    } while (nr <= 0);

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

    return Accounts(nr, balance, client);
}

// Function to print the details of a single account
<<<<<<< HEAD
void AccountView::printAccount(Accounts *account) {
    if (account) {
        cout << "Account Number: " << account->getNr() << endl;
        cout << "Balance: " << fixed << setprecision(2) << account->getBalance() << endl; // Assuming you have a getBalance() method in Accounts
        cout << "Client: " << account->getClient()->getName() << endl; // Assuming you have getClient() and getName() methods
    } else {
        cout << "Invalid Account (nullptr)" << endl;
    }
=======
void AccountView::printAccountInformation(Accounts *account) {
    cout << "Account Number: " << account->getNr() << endl;
    cout << "Balance: " << account->getBalance() << endl;
>>>>>>> parent of 5c509e1 (update)
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