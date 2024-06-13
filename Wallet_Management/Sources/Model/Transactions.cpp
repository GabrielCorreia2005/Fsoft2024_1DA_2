#include "Transactions.h"
#include "InvalidDataException.h"

Transactions::Transactions(float amount, const string& type, const Date& date, Accounts* originAccount, Accounts* destinationAccount) :
        amount(amount), type(type), date(date), originAccount(originAccount), destinationAccount(destinationAccount) {

    if (amount <= 0) {
        throw InvalidDataException("Transaction amount must be positive.");
    }
}

Transactions::Transactions(const Transactions &obj) :
        amount(obj.amount), type(obj.type), date(obj.date), originAccount(obj.originAccount),
        destinationAccount(obj.destinationAccount) {}

Transactions::~Transactions() {}

float Transactions::getAmount() const {
    return amount;
}

void Transactions::setAmount(float amount) {
    if (amount <= 0) {
        throw InvalidDataException("Transaction amount must be positive.");
    }
    this->amount = amount;
}

const string& Transactions::getType() const {
    return type;
}

void Transactions::setType(const string& type) {
    this->type = type;
}

const Date& Transactions::getDate() const {
    return date;
}

void Transactions::setDate(const Date& date) {
    this->date = date;
}

Accounts* Transactions::getOriginAccount() const {
    return originAccount;
}

void Transactions::setOriginAccount(Accounts* originAccount) {
    this->originAccount = originAccount;
}

Accounts* Transactions::getDestinationAccount() const {
    return destinationAccount;
}

void Transactions::setDestinationAccount(Accounts* destinationAccount) {
    this->destinationAccount = destinationAccount;
}

bool Transactions::operator==(const Transactions& rhs) const {
    return amount == rhs.amount &&
           type == rhs.type &&
           date == rhs.date &&
           (originAccount ? originAccount->getNr() : 0) == (rhs.originAccount ? rhs.originAccount->getNr() : 0) &&
           (destinationAccount ? destinationAccount->getNr() : 0) == (rhs.destinationAccount ? rhs.destinationAccount->getNr() : 0);
}