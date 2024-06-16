// Transactions.cpp 
#include "Transactions.h"

Transactions::Transactions(int transactionId, const Date &date, float amount, Client* client) :
        transactionId(transactionId), date(date), amount(amount), client(client) {}

Transactions::Transactions(const Transactions &obj) :
        transactionId(obj.transactionId), date(obj.date), amount(obj.amount), client(obj.client) {}

Transactions::~Transactions() {}


int Transactions::getTransactionId() const {
    return transactionId;
}

const Date &Transactions::getDate() const {
    return date;
}

float Transactions::getAmount() const {
    return amount;
}

Client* Transactions::getClient() const {
    return client;
}
void Transactions::setClient(Client* client) {
    this->client = client;
}

void Transactions::setAmount(float amount) {
    Transactions::amount = amount;
}


void Transactions::setDate(const Date& date) {
    this->date = date; // Set the date member variable
}

bool Transactions::operator==(const Transactions &rhs) const {
    return transactionId == rhs.transactionId;
}

// Remove the redundant setAccount function here