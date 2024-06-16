// Transactions.cpp 
#include "Transactions.h"

Transactions::Transactions(int transactionId, const Date &date, const string &type, float amount, Accounts *account) :
        transactionId(transactionId), date(date), type(type), amount(amount), account(account) {}

Transactions::Transactions(const Transactions &obj) :
        transactionId(obj.transactionId), date(obj.date), type(obj.type), amount(obj.amount), account(obj.account) {}

Transactions::~Transactions() {}


int Transactions::getTransactionId() const {
    return transactionId;
}

const Date &Transactions::getDate() const {
    return date;
}

const string &Transactions::getType() const {
    return type;
}

float Transactions::getAmount() const {
    return amount;
}

Accounts* Transactions::getAccount() const {
    return account;
}

void Transactions::setType(const string &type) {
    Transactions::type = type;
}

void Transactions::setAmount(float amount) {
    Transactions::amount = amount;
}

void Transactions::setAccount(Accounts *account) {
    Transactions::account = account;
}

void Transactions::setDate(const Date& date) {
    this->date = date; // Set the date member variable
}

bool Transactions::operator==(const Transactions &rhs) const {
    return transactionId == rhs.transactionId;
}

// Remove the redundant setAccount function here