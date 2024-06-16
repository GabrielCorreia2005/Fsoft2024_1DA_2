#ifndef WALLET_MANAGEMENT_TRANSACTIONS_H
#define WALLET_MANAGEMENT_TRANSACTIONS_H

#include <string>
#include "Date.h"
#include "Accounts.h" // Include the Accounts header

using namespace std;

class Transactions {
private:
    int transactionId;
    Date date;
    string type;
    float amount;
    Accounts *account; // Pointer to the associated account

public:
    // Constructor for creating a new transaction
    Transactions(int transactionId, const Date &date, const string &type, float amount, Accounts *account);
    // Copy constructor
    Transactions(const Transactions& obj);
    // Destructor
    ~Transactions();

    // Getters
    int getTransactionId() const;
    const Date& getDate() const;
    const string& getType() const;
    float getAmount() const;
    Accounts* getAccount() const;

    // Setters
    void setType(const string& type);
    void setAmount(float amount);
    void setAccount(Accounts *account);
    void setDate(const Date& date); // Add setDate() method

    // Overloaded equality operator for comparing transactions
    bool operator==(const Transactions& rhs) const;
};

#endif //WALLET_MANAGEMENT_TRANSACTIONS_H