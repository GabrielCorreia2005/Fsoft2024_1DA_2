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
    string name;
    /*

    InsuranceContainer insuranceContainer;

    void setDataForConsistency(); // Function to check and enforce data consistency
*/

    ClientsContainer clientsContainer;
    AccountsContainers accountsContainer;
    LoansContainers loansContainer;
    TransactionsContainers transactionsContainer;

public:
    // Constructors
    WalletManagement();
    WalletManagement(const string& name);
    //WalletManagement(const char *obj);
    const string getName() const;
    void setName(const string &name);
    /*
      // Getters for the containers


      InsuranceContainer &getInsuranceContainer();

      //por adicionar mais
      */
    ClientsContainer &getClientContainer();
    AccountsContainers &getAccountsContainer();
    LoansContainers &getLoansContainer();
    TransactionsContainers &getTransactionsContainer();

};

#endif //WALLET_MANAGEMENT_WALLETMANAGEMENT_H