//
// Created by gvice on 13/05/2024.
//

#include "Controller.h"
#include "Utils.h"
#include <iostream> // For input/output

using namespace std;

Controller::Controller(WalletManagement &walletManagement) : model(walletManagement) {}

void Controller::run() {
    int choice;
    do {
        // Display main menu (you'll need to define this content)
        choice = view.menuBank();

        switch (choice) {
            case 1: runAccount(); break;
            case 2: runClient(); break;
            case 3: runLoan(); break;
            case 4: runTransactions(); break;
            case 5: runInsurance(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

void Controller::runAccount() {
    int choice;
    do{
        choice = view.menuAccount();

        switch (choice) {
            case 1:{
                // Add Account
                Accounts account = accountView.getAccount(model.getClientContainer());
                try {
                    model.getAccountsContainer().add(account);
                    cout << "Account added successfully." << endl;
                } catch (DuplicatedDataException &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2:{
                // List Accounts
                list<Accounts> accounts = model.getAccountsContainer().getAll();
                accountView.printAccounts(accounts);
                break;
            }
            case 3:{
                // Remove Account
                int number = Utils::getNumber("Enter the account number to remove: ");
                try {
                    model.getAccountsContainer().remove(number);
                    cout << "Account removed successfully." << endl;
                } catch (const exception &e) { // Catch a more general exception if remove might throw other types
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4:{
                // Update Account (Example: Update balance)
                int number = Utils::getNumber("Enter the account number to update: ");
                float balance = Utils::getNumber("Enter the new balance: ");
                try {
                    model.getAccountsContainer().update(number, balance);
                    cout << "Account updated successfully." << endl;
                } catch (exception &e) { // Catch a more general exception here as well
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 0:
                break; // Exit the Account Management menu
            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    }while(choice != 0);
}

void Controller::runClient() {
    int option;
    do {
        option = view.menuClient();
        switch (option) {
            case 1: {
                // Add Client
                Client client = clientView.getClient();
                try {
                    model.getClientContainer().add(client);
                    cout << "Client added successfully." << endl;
                } catch (DuplicatedDataException e) {
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
                int number = Utils::getNumber("Enter the client number to remove: ");
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
                int number = Utils::getNumber("Enter the client number to update: ");
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
    // ... implement logic for managing loans
}

void Controller::runTransactions() {
    // ... implement logic for managing transactions
}

void Controller::runInsurance() {
    // ... implement logic for managing insurance
}