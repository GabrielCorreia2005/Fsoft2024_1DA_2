#ifndef WALLET_MANAGEMENT_INSURANCE_H
#define WALLET_MANAGEMENT_INSURANCE_H

#include <string>
#include "InvalidDataException.h"
#include "Client.h" // Include Client.h

using namespace std;

class Insurance {
private:
    string name;
    float price;
    float length;
    int installments;
    float fees;
    Client* client; // Pointer to the client holding this insurance
    bool isNameValid(const string& name);

public:
    Insurance() = default;
    Insurance(const string& name, float price, float length, int installments, float fees, Client* client);
    Insurance(const Insurance &obj);
    ~Insurance();

    const string& getName() const;
    float getPrice() const;
    float getLength() const;
    int getInstallments() const;
    float getFees() const;
    Client* getClient() const; // Getter for client

    void setName(const string& name);
    void setPrice(float price);
    void setLength(float length);
    void setInstallments(int installments);
    void setFees(float fees);
    void setClient(Client* client); // Setter for client

    bool operator==(const Insurance &rhs) const;
};

#endif //WALLET_MANAGEMENT_INSURANCE_H