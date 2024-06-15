//
// Created by gvice on 13/05/2024.
//

#include "Controller.h"
#include "Utils.h"
#include "WalletManagement.h"
#include "AccountView.h"
#include <iostream>


using namespace std;

Controller::Controller(WalletManagement &walletManagement) : model(walletManagement) {}

void Controller::run() {
    int choice;
    do {
        // Display main menu (you'll need to define this content)
        choice = view.menuBank();

        switch (choice) {
            case 1: runAccount(); break;
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
            case 1: {  // Create Account
                Client client = clientView.getClient(); // Get the client data with validation
                try {
                    model.getClientContainer().add(client);
                    cout << "Client added successfully." << endl;
                } catch (DuplicatedDataException &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: {
                // List Clients
                list<Client> clients = model.getClientContainer().getAll();
                clientView.printClients(clients);
                break;
            }
            case 3: {
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
            case 4: {
                // Update Client
                int number = Utils::getNumber("Enter the client number to update");
                string name = Utils::getString("Enter the new name: ");
                Date birth = clientView.getDate();
                try {
                    model.getClientContainer().update(number, name, birth);
                    cout << "Client updated successfully." << endl;
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

// In Controller.cpp
#include "Controller.h"
#include "Utils.h"
#include "WalletManagement.h"

void Controller::runAccount() {
    int option;
    do {
        option = view.menuAccount(); // Display the account menu

        switch (option) {
            case 1: { // Create Account
                try {
                    Client newClient = clientView.getClient();
                    model.getClientContainer().add(newClient);
                    Accounts newAccount = accountView.getAccount(model.getClientContainer());
                    model.getAccountsContainer().add(newAccount);
                    cout << "Client and Account created successfully!" << endl;
                } catch ( InvalidDataException& e) {
                    cerr << "Error: " << e.what() << endl;
                } catch ( DuplicatedDataException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: { // Monitor Account (For a specific client)
                int clientNumber = Utils::getNumber("Enter Client Number: ");
                Client *client = model.getClientContainer().get(clientNumber);
                if (client != nullptr) {
                    // Get all accounts associated with the client (you'll need to implement this logic)
                    list<Accounts> clientAccounts = model.getAccountsContainer().getAll();
                    if (!clientAccounts.empty()) {
                        accountView.printAccounts(clientAccounts);
                    } else {
                        cout << "Client has no accounts." << endl;
                    }
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 3: { // Close Account (For a specific client)
                int clientNumber = Utils::getNumber("Enter Client Number: ");
                Client *client = model.getClientContainer().get(clientNumber);
                if (client != nullptr) {
                    // Get all accounts associated with the client (you'll need to implement this logic)
                    list<Accounts> clientAccounts = model.getAccountsContainer().getAll();
                    if (!clientAccounts.empty()) {
                        // Display accounts and prompt for account selection
                        int accountChoice = Utils::getNumber("Choose account to close:");
                        if (accountChoice > 0 && accountChoice <= clientAccounts.size()) {
                            auto it = clientAccounts.begin();
                            advance(it, accountChoice - 1);
                            int accountNumber = (*it).getNr();
                            model.getAccountsContainer().remove(accountNumber);
                            cout << "Account closed successfully!" << endl;
                        } else {
                            cout << "Invalid account choice." << endl;
                        }
                    } else {
                        cout << "Client has no accounts." << endl;
                    }
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 4: { // List Clients
                list<Client> clients = model.getClientContainer().getAll();
                clientView.printClients(clients);
                break;
            }
            case 5: { // Remove Client
                int clientNumber = Utils::getNumber("Enter Client Number to Remove: ");
                if (model.getClientContainer().isThereClient(clientNumber)) {
                    // Remove the client and associated accounts
                    model.getClientContainer().remove(clientNumber);
                    cout << "Client and associated accounts removed successfully!" << endl;
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 0: // Exit
                cout << "Exiting Account Management..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

    } while (option != 0);
}

Client* Controller::selectClient() {
    int clientNumber = Utils::getNumber("Enter Client Number: ");

    Client* client = model.getClientContainer().get(clientNumber);
    if (client == nullptr) {
        cout << "Client not found!" << endl;
        return nullptr;
    }
    return client;
}

void Controller::runTransactions() {
    // ... implement logic for managing transactions
}

void Controller::runInsurance() {
    // ... implement logic for managing insurance
}