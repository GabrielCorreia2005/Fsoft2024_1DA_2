#ifndef WALLET_MANAGEMENT_TRANSACTIONS_H
#define WALLET_MANAGEMENT_TRANSACTIONS_H

#include <string>
#include "Date.h"
#include "Accounts.h" // Include the Accounts header
#include "Client.h"

using namespace std;

class Transactions {
private:
    int transactionId;
    Date date;
    float amount;
    Client* client; // Pointer to the associated account

public:
    // Constructor for creating a new transaction
    Transactions(int transactionId, const Date &date, float amount, Client* client);
    // Copy constructor
    Transactions(const Transactions& obj);
    // Destructor
    ~Transactions();

    // Getters
    int getTransactionId() const;
    const Date& getDate() const;
    const string& getType() const;
    float getAmount() const;
    Client* getClient() const;

    // Setters
    void setAmount(float amount);
    void setClient(Client* client);
    void setDate(const Date& date); // Add setDate() method

    // Overloaded equality operator for comparing transactions
    bool operator==(const Transactions& rhs) const;
};

#endif //WALLET_MANAGEMENT_TRANSACTIONS_H