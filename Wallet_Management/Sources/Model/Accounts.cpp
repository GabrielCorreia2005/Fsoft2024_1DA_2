#include "Accounts.h"

const float Accounts::MIN_BALANCE = 500;

Accounts::Accounts(int nr, float balance, Client *client) : nr(nr), balance(balance), client(client) {
    validateBalance(balance);
}

Accounts::Accounts(const Accounts &obj) : nr(obj.nr), balance(obj.balance), client(obj.client) {}

Accounts::~Accounts() {}

int Accounts::getNr() const {
    return nr;
}

float Accounts::getBalance() const {
    return balance;
}

Client* Accounts::getClient() const {
    return client;
}

void Accounts::setNumber(int &nr) {
    this->nr = nr;
}

void Accounts::setBalance(float balance) { // Update setBalance()
    this->balance = balance;
}

bool Accounts::isPointerNotNull(void *pointer) {
    return (pointer != nullptr);
}

void Accounts::validateBalance(float balance) const {
    if (balance < MIN_BALANCE) {
        throw InvalidDataException(
                "The balance must be at least " + to_string(MIN_BALANCE));
    }
}