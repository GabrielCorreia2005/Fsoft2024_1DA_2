#ifndef WALLET_MANAGEMENT_ACCOUNTS_H
#define WALLET_MANAGEMENT_ACCOUNTS_H

#include "Client.h"
#include "InvalidDataException.h"

using namespace std;

class Accounts {
private:
    static const float MIN_BALANCE; // Declare the minimum balance as a constant
    int nr;  // Account number
    float balance;
    Client * client;

    bool isPointerNotNull(void * pointer);

    // Add a validation function for the balance
    void validateBalance(float balance) const;

public:
    Accounts(int nr, float balance, Client * client);
    Accounts(const Accounts& obj);
    ~Accounts();

    int getNr() const; // This method goes here!
    float getBalance() const;
    Client *getClient() const;

    void setNumber(int &nr);
    void setBalance(float &balance);
    static float getMinBalance() {
        return MIN_BALANCE;
    }
};

#endif //WALLET_MANAGEMENT_ACCOUNTS_H