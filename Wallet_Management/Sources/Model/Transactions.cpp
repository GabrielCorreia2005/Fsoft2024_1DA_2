//
// Created by corre on 20/05/2024.
//

#include "Transactions.h"
#include "InvalidDataException.h"

Transactions::Transactions(float amount, const string& type, const Date& date, Accounts originAccount, AccountsdestinationAccount)
        : amount(amount), type(type), date(date), originAccount(originAccount), destinationAccount(destinationAccount) {
    if (amount <= 0) {
        throw InvalidDataException("Transaction amount must be greater than 0.");
    }
    // You might want to add validation for the transaction type here
}

Transactions::Transactions(const Transactions &obj)
        : amount(obj.amount), type(obj.type), date(obj.date), originAccount(obj.originAccount), destinationAccount(obj.destinationAccount) {}

Transactions::~Transactions() {}

float Transactions::getAmount() const {
    return amount;
}

void Transactions::setAmount(float amount) {
    if (amount <= 0) {
        throw InvalidDataException("Transaction amount must be greater than 0.");
    }
    Transactions::amount = amount;
}

const string& Transactions::getType() const {
    return type;
}

void Transactions::setType(const string& type) {
    Transactions::type = type;
}

const Date& Transactions::getDate() const {
    return date;
}

void Transactions::setDate(const Date& date) {
    Transactions::date = date;
}

Accounts* Transactions::getOriginAccount() const {
    return originAccount;
}

void Transactions::setOriginAccount(Accounts* originAccount) {
    Transactions::originAccount = originAccount;
}
Accounts* Transactions::getDestinationAccount() const {
    return destinationAccount;
}

void Transactions::setDestinationAccount(Accounts* destinationAccount) {
    Transactions::destinationAccount = destinationAccount;
}

bool Transactions::operator==(const Transactions& rhs) const {
    // You should define what makes two transactions equal based on your application logic
    // For example, you might compare amount, type, date, and account numbers
    return amount == rhs.amount &&
           type == rhs.type &&
           date == rhs.date &&
           (originAccount ? originAccount->getNumber() : 0) == (rhs.originAccount ? rhs.originAccount->getNumber() : 0) &&
           (destinationAccount ? destinationAccount->getNumber() : 0) == (rhs.destinationAccount ? rhs.destinationAccount->getNumber() : 0);
}
