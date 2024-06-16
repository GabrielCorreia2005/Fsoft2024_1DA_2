// Controller.h
#ifndef WALLET_MANAGEMENT_CONTROLLER_H
#define WALLET_MANAGEMENT_CONTROLLER_H

#include "View.h"
#include "AcquireView.h"
#include "AccountView.h"
#include "ClientView.h"
#include "InsuranceView.h"
#include "LoanView.h"
#include "TransactionsView.h" // Add TransactionsView header
#include "WalletManagement.h"

class Controller{

private:
    View view;
    /*
    AcquireView acquireView;
    InsuranceView insuranceView;
    */
    Client* selectClient(); // Declare the function
    AccountView accountView;
    ClientView clientView;
    LoanView loanView;
    TransactionsView transactionsView; // Add TransactionsView to the private section
    // Private functions to handle specific modules
    void runClient();
    void runLoan();
    void runTransactions();
    void runInsurance();
    void runBank();
    void runAccount(); // New method to handle account options
    void runAccountInformation(); // New method

    WalletManagement model;

public:
    // Constructor
    Controller(WalletManagement& walletManagement);

    // Main run function of the application
    void run();
};
#endif //WALLET_MANAGEMENT_CONTROLLER_H