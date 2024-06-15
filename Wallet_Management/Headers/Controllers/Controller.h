//
// Created by gvice on 13/05/2024.
//

#ifndef WALLET_MANAGEMENT_CONTROLLER_H
#define WALLET_MANAGEMENT_CONTROLLER_H

#include "View.h"
#include "AcquireView.h"
#include "AccountView.h"
#include "ClientView.h"
#include "InsuranceView.h"
#include "LoanView.h"
#include "TransactionsView.h"
#include "WalletManagement.h"

class Controller{

private:
    View view;
    /*
    AcquireView acquireView;
    InsuranceView insuranceView;

    TransactionsView transactionsView;*/

    AccountView accountView;
    ClientView clientView;
    LoanView loanView;
    // Private functions to handle specific modules
    void runClient();
    void runLoan();
    void runTransactions();
    void runInsurance();
    void runBank();
    void runAccountInformation(); // New method

    WalletManagement model;

public:
    // Constructor
    Controller(WalletManagement& walletManagement);

    // Main run function of the application
    void run();
};
#endif //WALLET_MANAGEMENT_CONTROLLER_H