//
// Created by corre on 20/05/2024.
//

#ifndef WALLET_MANAGEMENT_TRANSACTIONS_H
#define WALLET_MANAGEMENT_TRANSACTIONS_H

#include <string>
#include "Date.h"
#include "Accounts.h"
#include "InvalidDataException.h"

using namespace std;

class Transactions {
private:
    float amount;            // The amount of money involved in the transaction
    string type;            // The type of transaction (e.g., "Deposit", "Withdrawal", "Transfer")
    Date date;              // The date of the transaction
    Accounts* originAccount;      // Pointer to the origin account (can be nullptr if not applicable)
    Accounts* destinationAccount; // Pointer to the destination account (can be nullptr if not applicable)

public:
    // Constructor: Takes transaction amount, type, date, and pointers to origin and destination accounts
    Transactions(float amount, const string& type, const Date& date, Accounts* originAccount = nullptr, Accounts* destinationAccount = nullptr);

    // Copy Constructor
    Transactions(const Transactions &obj);

    // Destructor
    ~Transactions();

    // Getters and Setters for the private member variables
    float getAmount() const;
    void setAmount(float amount); // Throws an exception if the amount is not positive

    const string& getType() const;
    void setType(const string& type);

    const Date& getDate() const;
    void setDate(const Date& date);

    Accounts* getOriginAccount() const;
    void setOriginAccount(Accounts* originAccount);

    Accounts* getDestinationAccount() const;
    void setDestinationAccount(Accounts* destinationAccount);

    // Equality operator: Define what makes two transactions equal based on your application logic
    bool operator==(const Transactions& rhs) const;
};

#endif //WALLET_MANAGEMENT_TRANSACTIONS_H