#include "Loans.h"
#include "Client.h"

const float Loans::fixedInterestRate = 0.04f;

Loans::Loans(int accountNumber, const string& type, float amount, int durationMonths, Client* client) :
        accountNumber(accountNumber), type(type), amount(amount), durationMonths(durationMonths), client(client) {}

Loans::Loans(const Loans &obj) :
        accountNumber(obj.accountNumber), type(obj.type), amount(obj.amount),
        durationMonths(obj.durationMonths), client(obj.client) {}

Loans::~Loans() = default;

const string &Loans::getType() const {
    return type;
}

void Loans::setType(const string &type) {
    Loans::type = type;
}

float Loans::getAmount() const {
    return amount;
}

void Loans::setAmount(float amount) {
    Loans::amount = amount;
}

float Loans::getFixedInterestRate() const {
    return fixedInterestRate;
}

int Loans::getDurationMonths() const {
    return durationMonths;
}

void Loans::setDurationMonths(int durationMonths) {
    Loans::durationMonths = durationMonths;
}

int Loans::getAccountNumber() const {
    return accountNumber;
}

Client* Loans::getClient() const {
    return client;
}

void Loans::setClient(Client* client) {
    Loans::client = client;
}

bool Loans::operator==(const Loans &rhs) const {
    return accountNumber == rhs.accountNumber && client == rhs.client;
}
