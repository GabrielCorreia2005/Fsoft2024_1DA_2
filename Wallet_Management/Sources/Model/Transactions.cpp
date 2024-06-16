// Transactions.cpp 
#include "Transactions.h"

Transactions::Transactions(int transactionId, const Date &date, float amount, Accounts *account) :
        transactionId(transactionId), date(date), amount(amount), account(account) {}

Transactions::Transactions(const Transactions &obj) :
        transactionId(obj.transactionId), date(obj.date), amount(obj.amount), account(obj.account) {}

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

Accounts* Transactions::getAccount() const {
    return account;
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