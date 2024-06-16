//
// Created by gvice on 13/05/2024.
//

#include "Controller.h"
#include "Utils.h"
#include <iostream>


using namespace std;

Controller::Controller(WalletManagement &walletManagement) : model(walletManagement) {}

void Controller::run() {
    int choice;
    do {
        // Display main menu (you'll need to define this content)
        choice = view.menuBank();

        switch (choice) {
            case 1: runClient(); break;
            case 2: runLoan(); break;
            case 3: runTransactions(); break;
            case 4: runInsurance(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}


void Controller::runClient() {
    int option;
    do {
        option = view.menuClient();
        switch (option) {
            case 1: {
                // Create Account (Modified Logic)
                string name = Utils::getString("Name");
                // Validate name (Check if it's at least 3 characters long)
                while (!Client::isNameValid(name)) {
                    cout << "Invalid name. Name must be at least 3 characters long." << endl;
                    name = Utils::getString("Name");
                }

                Date birth = clientView.getDate();

                // Create the Client object
                Client newClient(name, birth, ClientsContainer::nextClientNumber);

                // Add the Client to the container
                model.getClientContainer().add(newClient);

                // Prompt for initial balance
                float balance;
                do {
                    balance = Utils::getNumber("Initial Balance::");
                    if (balance < Accounts::getMinBalance()) { // Use the getter
                        cout << "Initial balance must be at least " << Accounts::getMinBalance() << endl;
                    }
                } while (balance < Accounts::getMinBalance());

                // Create the Account object
                Accounts newAccount(newClient.getNumber(), balance, &newClient);

                // Add the Account to the container
                model.getAccountsContainer().add(newAccount);

                cout << "Client and account added successfully." << endl;
                break;
            }
            case 2: {
                // List Clients
                list<Client> clients = model.getClientContainer().getAll();
                clientView.printClients(clients);
                break;
            }
            case 3: {
                // Account Information (New Logic)
                int clientNumber = Utils::getNumber("Enter client number: ");

                // Get the client object
                Client* client = model.getClientContainer().get(clientNumber);

                // Check if the client exists
                if (client != nullptr) {
                    // Get the account associated with the client (assuming one account per client)
                    Accounts* account = model.getAccountsContainer().get(client->getNumber());

                    if (account != nullptr) {
                        // Display account information
                        accountView.printAccount(account);
                    } else {
                        cout << "Client does not have an account." << endl;
                    }
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 4: {
                // Remove Client
                int number = Utils::getNumber("Enter the client number to remove");
                try {
                    model.getClientContainer().remove(number);
                    cout << "Client removed successfully." << endl;
                } catch (const exception &e) { // Consider catching specific exceptions
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 0:
                break; // Exit the Client Management menu
            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    } while (option != 0);
}


void Controller::runLoan() {
    int option;
    do {
        option = view.menuLoans();
        switch (option) {
            case 1: { // Acquire Loan
                int AccountNumber = Utils::getNumber("Enter account number: ");
                Client* client = model.getClientContainer().get(AccountNumber);
                if (client) {
                    try {
                        Loans loan = loanView.getLoan(AccountNumber, client);
                        model.getLoansContainer().add(loan, client);
                        cout << "Loan added successfully." << endl;
                    }catch (const InvalidDataException& e) {
                        cerr << "Error: " << static_cast<InvalidDataException&>(const_cast<InvalidDataException &>(e)).what() << endl;
                    } catch (const DuplicatedDataException& e) {
                        cerr << "Error: " << static_cast<DuplicatedDataException&>(const_cast<DuplicatedDataException &>(e)).what() << " duplicated!!" << endl;
                    }
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 2: {
                // List Loans
                list<Loans> loans = model.getLoansContainer().getAll();
                loanView.printLoans(loans);
                break;
            }
            case 3: { // Monitor Loan
                int clientNumber = Utils::getNumber("Enter the client number: ");
                Client *client = model.getClientContainer().get(clientNumber);
                if (client) {
                    list<Loans> clientLoans;
                    for (const Loans &loan: model.getLoansContainer().getAll()) {
                        if (loan.getClient() == client) {
                            clientLoans.push_back(loan);
                        }
                    }
                    loanView.printLoans(clientLoans); // Print loans associated with the client
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 4: {
                // Update Loan (Example: Update interest rate or duration)
                string type = Utils::getString("Enter the loan type to update:");
                float amount = Utils::getNumber("Enter the loan amount to update:");
                float newInterestRate = Utils::getNumber("Enter the new interest rate:");
                int newDurationMonths = Utils::getNumber("Enter the new loan duration (in months):");

                try {
                    model.getLoansContainer().update(type, amount, newInterestRate, newDurationMonths);
                    cout << "Loan updated successfully." << endl;
                } catch (const exception &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 0:
                break; // Exit the Loan Management menu
            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    } while (option != 0);
}

Client* Controller::selectClient() {
    int clientNumber = Utils::getNumber("Enter Client Number: ");
    Client *client = model.getClientContainer().get(clientNumber);
    if (client != nullptr) {
        return client;
    } else {
        cout << "Client not found." << endl;
        return nullptr;
    }
}

void Controller::runTransactions() {
    int choice;
    do {
        choice = view.menuTransactions();

        switch (choice) {
            case 1: {
                // Make Transaction
                Client* client = selectClient();
                if (client != nullptr) {
                    Accounts* account = model.getAccountsContainer().get(client->getNumber());
                    if (account != nullptr) {
                        Transactions newTransaction = transactionsView.getTransaction(account); // Get transaction
                        try {
                            model.getTransactionsContainer().add(newTransaction);
                            cout << "Transaction registered successfully!" << endl;
                        } catch (const InvalidDataException &e) {
                            cout << "Error: " << e.what() << endl;
                        }
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;
            }
            case 2: {
                // View Transaction History
                Client* client = selectClient();
                if (client != nullptr) {
                    Accounts* account = model.getAccountsContainer().get(client->getNumber());
                    if (account != nullptr) {
                        list<Transactions> transactions = model.getTransactionsContainer().getAll();
                        transactionsView.printTransactions(transactions);
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                break;
            }
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 0);
}

void Controller::runInsurance() {
    // ... implement logic for managing insurance
}