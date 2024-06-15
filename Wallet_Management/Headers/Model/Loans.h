#ifndef WALLET_MANAGEMENT_LOANS_H
#define WALLET_MANAGEMENT_LOANS_H

#include <string>
#include "InvalidDataException.h"

using namespace std;

class Client; // Forward declaration of the Client class

class Loans {
private:
    int accountNumber;
    string type;
    float amount;
    int durationMonths;
    static const float fixedInterestRate;
    Client *client;

public:
    Loans(int accountNumber, const string& type, float amount, int durationMonths, Client* client);
    Loans(const Loans &obj);
    ~Loans();

    const string& getType() const;
    void setType(const string& type);

    float getAmount() const;
    void setAmount(float amount);

    static float getFixedInterestRate();

    int getDurationMonths() const;
    void setDurationMonths(int durationMonths);

    int getAccountNumber() const;

    Client* getClient() const;
    void setClient(Client* client);

    bool operator==(const Loans& rhs) const;
};

#endif //WALLET_MANAGEMENT_LOANS_H