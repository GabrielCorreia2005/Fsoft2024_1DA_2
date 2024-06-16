//
// Created by gvice on 13/05/2024.
//

#include "Controller.h"
#include "Utils.h"
#include <iostream>


using namespace std;

Controller::Controller(WalletManagement &walletManagement) : model(walletManagement) {}

void Controller::run() {
    int option;
    do {
        // Display main menu (you'll need to define this content)
        option = view.menuBank();

        switch (option) {
            case 1: runClient(); break;
            case 2: runLoan(); break;
            case 3: runTransactions(); break;
            case 4: runInsurance(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (option != 0);
}


void Controller::runClient() {
    int option;
    do {
        option = view.menuClient();
        switch (option) {
            case 1: {
                try {
                    // Create Account (Modified Logic)
                    Client newClient = clientView.getClient();
                    model.getClientContainer().add(newClient);

                    // Prompt for initial balance
                    float balance;
                    do {
                        balance = Utils::getNumber("Initial Balance:");
                        if (balance < Accounts::getMinBalance()) {
                            cout << "Initial balance must be at least " << Accounts::getMinBalance() << endl;
                        }
                    } while (balance < Accounts::getMinBalance());

                    // Create the Account object
                    Accounts newAccount(newClient.getNumber(), balance, &newClient);
                    model.getAccountsContainer().add(newAccount);

                    cout << "Account added successfully." << endl;
                } catch (const InvalidDataException& e) {
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
                // Account Information
                int clientNumber = Utils::getNumber("Enter client number: ");
                Client* client = model.getClientContainer().get(clientNumber);
                if (client != nullptr) {
                    Accounts* account = model.getAccountsContainer().get(clientNumber);
                    if (account != nullptr) {
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
                // Delete Account
                int clientNumberToDelete = Utils::getNumber("Enter client number to delete: ");
                try {
                    model.getClientContainer().remove(clientNumberToDelete);
                    model.getAccountsContainer().remove(clientNumberToDelete);
                    cout << "Client and account deleted successfully." << endl;
                } catch (const exception& e) {
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
            case 1: {
                try {
                    int accountNumber = Utils::getNumber("Enter account number: ");
                    string type = Utils::getString("Enter the loan type: ");
                    float amount = (float)Utils::getNumber("Enter the loan amount: ");
                    int durationMonths = Utils::getNumber("Enter the loan duration in months: ");

                    Client *client = model.getClientContainer().get(accountNumber);
                    if (client != nullptr) {
                        Loans loan(accountNumber, type, amount, durationMonths, client);
                        model.getLoansContainer().add(loan, client, model.getAccountsContainer()); // Pass accountsContainer here
                        cout << "Loan added successfully." << endl;
                    }
                }
                catch (InvalidDataException &e) {
                    cout << "Error: " << e.what() << endl;
                }
                catch (DuplicatedDataException &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: { // List Loans
                // Assuming you have a way to get loans associated with a client
                Client* client = selectClient();
                if (client != nullptr) {
                    list<Loans> clientLoans = model.getLoansContainer().getAll(); // You'll likely need a different function in LoansContainers to get loans by client
                    loanView.printLoans(clientLoans);
                }
                break;
            }
            case 3: { // Loan Details
                int clientNumber = Utils::getNumber("Enter the client number: ");
                Client* client = model.getClientContainer().get(clientNumber);
                if (client != nullptr) {
                    list<Loans> loans = model.getLoansContainer().getAll(); // Retrieve all loans

                    // Filter loans based on the client
                    list<Loans> clientLoans;
                    for (const Loans& loan : loans) {
                        if (loan.getClient()->getNumber() == clientNumber) {
                            clientLoans.push_back(loan);
                        }
                    }

                    cout << "List of loans: " << endl;
                    loanView.printLoans(clientLoans); // Now print the filtered clientLoans
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 4:
                runAmortizeLoan();
                break;
            case 0:
                // Exit the loan menu
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
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
    int option;

    do {
        option = view.menuTransactions();

        switch (option) {
            case 1: { // Add Transaction
                // 1. Get Source and Destination Accounts from the View
                int sourceClientNumber = Utils::getNumber("Enter Source Client Number: ");
                Client* sourceClient = model.getClientContainer().get(sourceClientNumber);
                if (sourceClient == nullptr) {
                    cout << "Source client not found." << endl;
                    break; // Exit to the transactions menu
                }


                int destClientNumber = Utils::getNumber("Enter Destination Client Number: ");
                Client* destClient = model.getClientContainer().get(destClientNumber);
                if (destClient == nullptr) {
                    cout << "Destination client not found." << endl;
                    break;
                }
                Client* desClient = reinterpret_cast<Client *>(model.getClientContainer().get(destClientNumber));
                if (destClient == nullptr) {
                    cout << "Destination account not found." << endl;
                    break;
                }

                // 2. Get Transaction Details from the View
                Transactions newTransaction = transactionsView.getTransaction(sourceClient, destClient);

                    if (sourceClient->getBalance() >= newTransaction.getAmount()) {
                        sourceClient->setBalance(sourceClient->getBalance() - newTransaction.getAmount());
                        destClient->setBalance(destClient->getBalance() + newTransaction.getAmount());
                        cout << "Transaction added successfully!" << endl;
                    } else {
                        cout << "Error: Insufficient funds in the source account." << endl;
                        break;
                    }

                // 4. Add the Transaction to the Model (if balances were updated successfully)
                model.getTransactionsContainer().add(newTransaction);
                break;
            }
            case 2: {
                // List Transactions Logic (similar to your existing code)
                list<Transactions> allTransactions = model.getTransactionsContainer().getAll();
                transactionsView.printTransactions(allTransactions);
                break;
            }
            case 0:
                cout << "Exiting Transactions Menu." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (option != 0);
}


void Controller::runInsurance() {
    int option;
    do {
        option = view.menuInsurance();
        switch (option) {
            case 1: { // Add insurance
                try {
                    Insurance insurance = insuranceView.getInsurance(model.getClientContainer());
                    model.getInsuranceContainer().add(insurance);
                    cout << "Insurance added successfully." << endl;
                } catch ( InvalidDataException &e) {
                    cout << "Error: " << e.what() << endl;
                } catch ( DuplicatedDataException &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: { // List insurances
                list<Insurance> insurances = model.getInsuranceContainer().getAll();
                insuranceView.printInsurances(insurances);
                break;
            }
            case 3: // Monitor insurance for a client
                runMonitorInsurance();
                break;
            case 0: // Back to main menu
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 0);
}

void Controller::runMonitorInsurance() {
    int clientNumber = Utils::getNumber("Enter client number: ");
    Client* client = model.getClientContainer().get(clientNumber);
    if (client == nullptr) {
        cout << "Client not found." << endl;
        return;
    }

    list<Insurance> clientInsurances = model.getInsuranceContainer().getClientInsurances(clientNumber);
    if (clientInsurances.empty()) {
        cout << "Client has no insurances." << endl;
    } else {
        cout << "\nInsurances for client " << client->getName() << ":" << endl;
        insuranceView.printInsurances(clientInsurances);
    }
}

void Controller::runAmortizeLoan() {
    int clientNumber = Utils::getNumber("Enter the client number: ");
    string type = Utils::getString("Enter the loan type: ");
    float amount = Utils::getNumber("Enter the loan amount: ");
    float paymentAmount = Utils::getNumber("Enter the payment amount: ");

    float remainingBalance = model.getLoansContainer().amortizeLoan(clientNumber, type, amount, paymentAmount);

    if (remainingBalance >= 0) {
        // Loan found and potentially amortized
        Accounts *account = model.getAccountsContainer().get(clientNumber); // Assuming account number is the same as client number
        if (account) {
            if (remainingBalance == 0.0f) {
                // Loan fully paid, no need to deduct from balance
            } else {
                float newBalance = account->getBalance() - paymentAmount;
                account->setBalance(newBalance);
            }
        } else {
            cout << "Account not found!" << endl;
        }
    }
}