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
    AcquireView acquireView; // Add AcquireView to the private section
    InsuranceView insuranceView; // Add InsuranceView to the private section
    Client* selectClient();
    AccountView accountView;
    ClientView clientView;
    LoanView loanView;
    TransactionsView transactionsView;
    void runClient();
    void runLoan();
    void runTransactions();
    void runInsurance();
    void runMonitorInsurance();
    void runBank();
    void runAccount();
    void runAccountInformation();

    WalletManagement model;

public:
    Controller(WalletManagement& walletManagement);
    void run();

    // New function to amortize a loan
    void runAmortizeLoan();
};
#endif //WALLET_MANAGEMENT_CONTROLLER_H