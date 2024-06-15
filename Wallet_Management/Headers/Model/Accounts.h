//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_ACCOUNTS_H
#define WALLET_MANAGEMENT_ACCOUNTS_H

#include "Client.h"
#include "InvalidDataException.h" // Include for balance validation

using namespace std;

class Accounts{

private:
    Accounts(int nr, float balance, void* client); // Modify the private constructor to accept a Client*
    int nr;
    float balance;
    Client * client;

    bool isPointerNotNull(void* pointer);
    void setNumber(int newNr) { //  Make sure setNumber is not const
        nr = newNr;
    }
public:
    Accounts(int nr, float balance, Client* client); // Accept Client* in the constructor
    Accounts(const Accounts& obj);
    ~Accounts();
    int getNr() const;
    float getBalance() const;
    Client *getClient() const;

    void setNumber(int &nr);
    void setBalance(float &balance);
    void setClient(Client* client);

    // Add a validation function for the balance
    static bool isBalanceValid(float balance);
};


#endif //WALLET_MANAGEMENT_ACCOUNTS_H