//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACCOUNTS_H
#define WALLET_MANAGEMENT_ACCOUNTS_H

#include "Client.h"

using namespace std;

class Accounts{

private:
    int nr;
    float balance;
    Client * client;
    bool isPointerNotNull(void * pointer);

public:
    Accounts(int nr, float balance, Client * client);
    Accounts(const Accounts& obj);
    ~Accounts();


};


#endif //WALLET_MANAGEMENT_ACCOUNTS_H
