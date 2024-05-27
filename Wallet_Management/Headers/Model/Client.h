//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACCOUNTS_H
#define WALLET_MANAGEMENT_ACCOUNTS_H

#include "Client.h"

using namespace std;

class Client{

private:
    char name
    int number;
    float birth;
    bool isPointerNotNull(void * pointer);

public:
    Client(char name, int nr, float birth);
    Accounts(const Client& obj);
    ~Client();


};


#endif //WALLET_MANAGEMENT_ACCOUNTS_H
