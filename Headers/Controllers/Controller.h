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
    AcquireView acquireView;
    AccountView accountView;
    ClientView clientView;
    InsuranceView insuranceView;
    LoanView loanView;
    TransactionsView transactionsView;
    WalletManagement model;
    void runAccount(), runClient(), runLoan(), runTransactions(), runInsurance();

public:
    Controller(WalletManagement& walletManagement);
    void run();
};
#endif //WALLET_MANAGEMENT_CONTROLLER_H