//
// Created by Gabriel on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_WALLETMANAGEMENT_H
#define WALLET_MANAGEMENT_WALLETMANAGEMENT_H

#include "ClientsContainer.h"
#include "AccountsContainers.h"
#include "LoansContainers.h"
#include "InsuranceContainer.h"
#include "TransactionsContainers.h"

class WalletManagement {
private:
    /*
    LoansContainers loansContainer;
    InsuranceContainer insuranceContainer;
    TransactionsContainers transactionsContainer;

    void setDataForConsistency(); // Function to check and enforce data consistency
*/

    ClientsContainer clientsContainer;
    AccountsContainers accountsContainer;

public:
    // Constructors
    WalletManagement();
    WalletManagement(const char *obj);
    /*
      // Getters for the containers

      LoansContainers &getLoansContainer();
      InsuranceContainer &getInsuranceContainer();
      TransactionsContainers &getTransactionsContainer();

      //por adicionar mais
      */
    ClientsContainer &getClientContainer();
    AccountsContainers &getAccountsContainer();


};

#endif //WALLET_MANAGEMENT_WALLETMANAGEMENT_H